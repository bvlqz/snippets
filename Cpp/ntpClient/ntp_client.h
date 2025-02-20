#ifndef NTP_CLIENT_H
#define NTP_CLIENT_H

#include <boost/asio.hpp>
#include <string>
#include <chrono>

class NTPClient {
public:
    explicit NTPClient(const std::string& server = "time.google.com", int port = 123);

    std::chrono::system_clock::time_point getNetworkTime();

private:
    std::string server_;
    int port_;
    boost::asio::io_context io_context_;
};

#endif // NTP_CLIENT_H
