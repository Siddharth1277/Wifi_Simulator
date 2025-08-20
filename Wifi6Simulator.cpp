#include <iostream>
#include <vector>
#include "WiFi6Simulator.h"

// Set a realistic max throughput for WiFi 6 (802.11ax).
WiFi6Simulator::WiFi6Simulator() : AccessPoint(1200.0) {}

void WiFi6Simulator::simulate(const std::vector<User>& users, double packetSizeKB) {
    if (users.empty()) return;

    double throughputPerUser = maxThroughput / users.size();
    double packetSizeMb = packetSizeKB / 125.0; // Kilobytes to Megabits

    // --- OFDMA Latency Model ---
    // Latency is ONLY your own transmission time. There is no waiting for others.
    double avgLatency = (packetSizeMb / throughputPerUser) * 1000.0;

    std::cout << "WiFi6 Simulation (OFDMA)    - Users: " << users.size()
              << ", AP Throughput: " << maxThroughput << " Mbps"
              << ", Avg User Throughput: " << throughputPerUser << " Mbps"
              << ", Average Latency: " << avgLatency << " ms\n";
}