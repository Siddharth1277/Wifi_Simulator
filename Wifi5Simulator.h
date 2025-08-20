#ifndef WIFI5SIMULATOR_H
#define WIFI5SIMULATOR_H

#include "AccessPoint.h"

class WiFi5Simulator : public AccessPoint {
public:
    WiFi5Simulator();
    void simulate(const std::vector<User>& users, double packetSizeKB) override;
};

#endif // WIFI5SIMULATOR_H