#include "ntp_client.h"
#include <boost/asio/ip/udp.hpp>
#include <iostream>

NTPClient::NTPClient(const std::string& server, int port)
    : server_(server), port_(port), io_context_() {}

std::chrono::system_clock::time_point NTPClient::getNetworkTime() {
    using namespace boost::asio;
    ip::udp::socket socket(io_context_);
    ip::udp::resolver resolver(io_context_);
    ip::udp::endpoint receiver_endpoint = *resolver.resolve(ip::udp::v4(), server_, std::to_string(port_)).begin();

    socket.open(ip::udp::v4());

    // NTP request packet (48 bytes)
    std::array<uint8_t, 48> request{};
    request[0] = 0b11100011; // LI = 3 (no warning), Version = 4, Mode = 3 (client)

    socket.send_to(buffer(request), receiver_endpoint);

    std::array<uint8_t, 48> response{};
    ip::udp::endpoint sender_endpoint;
    socket.receive_from(buffer(response), sender_endpoint);

    // Extract timestamps (seconds since 1900)
    uint32_t seconds_since_1900 = (response[40] << 24) | (response[41] << 16) | (response[42] << 8) | response[43];

    // Convert to seconds since UNIX epoch (1970)
    uint32_t seconds_since_unix_epoch = seconds_since_1900 - 2208988800U;

    return std::chrono::system_clock::time_point(std::chrono::seconds(seconds_since_unix_epoch));
}
