#include <vector>
#include <iostream>
#include "WiFi4Simulator.h"
#include "WiFi5Simulator.h"
#include "WiFi6Simulator.h"
#include "User.h"

int main() {
    // Simulation parameter
    const double PACKET_SIZE_KB = 1500.0; // A standard packet size

    // Create user groups
    std::vector<User> users1 = { User(1) };
    std::vector<User> users10;
    for (int i = 1; i <= 10; i++) users10.push_back(User(i));
    std::vector<User> users100;
    for (int i = 1; i <= 100; i++) users100.push_back(User(i));

    // --- WiFi 4 Simulation ---
    WiFi4Simulator wifi4;
    wifi4.simulate(users1, PACKET_SIZE_KB);
    wifi4.simulate(users10, PACKET_SIZE_KB);
    wifi4.simulate(users100, PACKET_SIZE_KB);
    std::cout << "--------------------------------------------------------------------------------\n";

    // --- WiFi 5 Simulation ---
    WiFi5Simulator wifi5;
    wifi5.simulate(users1, PACKET_SIZE_KB);
    wifi5.simulate(users10, PACKET_SIZE_KB);
    wifi5.simulate(users100, PACKET_SIZE_KB);
    std::cout << "--------------------------------------------------------------------------------\n";

    // --- WiFi 6 Simulation ---
    WiFi6Simulator wifi6;
    wifi6.simulate(users1, PACKET_SIZE_KB);
    wifi6.simulate(users10, PACKET_SIZE_KB);
    wifi6.simulate(users100, PACKET_SIZE_KB);

    return 0;
}