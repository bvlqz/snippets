from pathlib import Path
import logging as log
import argparse
import concurrent.futures

"""
usage: python-script.py [-h] [-j [JOBS]] [-v] [STRING]

Template of python script with argparse and ProcessPoolExecutor

positional arguments:
  [STRING]              Required string argument to print

optional arguments:
  -h, --help            show this help message and exit
  -j [JOBS], --jobs [JOBS]
                        jobs (max_workers)
  -v, --verbose         verbose output (set debug level)


Jorge Alberto Becerra
jorge@koruke.com
2021-10-09
"""

log.basicConfig(format='[%(levelname)s at %(processName)s\t%(asctime)s] %(message)s', 
                datefmt='%I:%M:%S %p',
                level=log.INFO)


def concurrentFunc(a, b):
    res = a + b;
    log.info(f"{a} + {b} = {res}")
    return res
    
def main():
    argumentParser = argparse.ArgumentParser(description="Template of python script with argparse and ProcessPoolExecutor")
    argumentParser.add_argument("String", metavar="[STRING]", type=str, help="Required string argument to print")
    argumentParser.add_argument("-j", "--jobs", metavar="[JOBS]", default=0, type=int, help="jobs (max_workers)")
    argumentParser.add_argument("-v", "--verbose", help="verbose output (set debug level)", action="store_true")
    commandLineArguments = argumentParser.parse_args()
	
    if commandLineArguments.verbose: log.getLogger().setLevel(log.DEBUG)
    log.debug(f"Verbose output is on")

    log.info(f"String argument: {commandLineArguments.String}")


    aNums = [a for a in range(10)]
    bNums = [b for b in range(10)]
    with concurrent.futures.ProcessPoolExecutor(max_workers=commandLineArguments.jobs) as executor:
        executor.map(concurrentFunc, aNums, bNums)
    
    log.info("Done")
	
if __name__ == '__main__':
    main()