#ifndef WIFI6SIMULATOR_H
#define WIFI6SIMULATOR_H

#include "AccessPoint.h"

class WiFi6Simulator : public AccessPoint {
public:
    WiFi6Simulator();
    void simulate(const std::vector<User>& users, double packetSizeKB) override;
};

#endif // WIFI6SIMULATOR_H