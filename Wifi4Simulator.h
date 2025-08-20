#ifndef WIFI4SIMULATOR_H
#define WIFI4SIMULATOR_H

#include "AccessPoint.h"

class WiFi4Simulator : public AccessPoint {
public:
    WiFi4Simulator();
    void simulate(const std::vector<User>& users, double packetSizeKB) override;
};

#endif // WIFI4SIMULATOR_H