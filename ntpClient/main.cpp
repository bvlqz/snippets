#include <iostream>
#include "ntp_client.h"

int main() {
    try {
        NTPClient ntpClient;
        auto networkTime = ntpClient.getNetworkTime();
        auto time_t_format = std::chrono::system_clock::to_time_t(networkTime);

        std::cout << "Current network time: " << std::ctime(&time_t_format);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
