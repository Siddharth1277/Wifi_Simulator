#include <iostream>
#include <vector>
#include "WiFi5Simulator.h"

// Set a realistic max throughput for WiFi 5 (802.11ac).
WiFi5Simulator::WiFi5Simulator() : AccessPoint(600.0) {}

void WiFi5Simulator::simulate(const std::vector<User>& users, double packetSizeKB) {
    if (users.empty()) return;

    double throughputPerUser = maxThroughput / users.size();
    double packetSizeMb = packetSizeKB / 125.0; // Kilobytes to Megabits

    // --- CSMA/CA Latency Model ---
    double ownTxTimeMs = (packetSizeMb / throughputPerUser) * 1000.0;
    
    // Total latency is your own transmission time plus waiting for every other user.
    double avgLatency = ownTxTimeMs * users.size();

    std::cout << "WiFi5 Simulation (CSMA/CA) - Users: " << users.size()
              << ", AP Throughput: " << maxThroughput << " Mbps"
              << ", Avg User Throughput: " << throughputPerUser << " Mbps"
              << ", Average Latency: " << avgLatency << " ms\n";
}