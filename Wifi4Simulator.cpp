#include <iostream>
#include <vector>
#include "WiFi4Simulator.h"

// Set a realistic max throughput for WiFi 4 (802.11n).
WiFi4Simulator::WiFi4Simulator() : AccessPoint(150.0) {}

void WiFi4Simulator::simulate(const std::vector<User>& users, double packetSizeKB) {
    if (users.empty()) return;

    double throughputPerUser = maxThroughput / users.size();
    double packetSizeMb = packetSizeKB / 125.0; // Kilobytes to Megabits

    // --- CSMA/CA Latency Model ---
    double ownTxTimeMs = (packetSizeMb / throughputPerUser) * 1000.0;
    
    // Total latency is your own transmission time plus waiting for every other user.
    double avgLatency = ownTxTimeMs * users.size();

    std::cout << "WiFi4 Simulation (CSMA/CA) - Users: " << users.size()
              << ", AP Throughput: " << maxThroughput << " Mbps"
              << ", Avg User Throughput: " << throughputPerUser << " Mbps"
              << ", Average Latency: " << avgLatency << " ms\n";
}