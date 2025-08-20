#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

#include <vector>
#include "User.h"

class AccessPoint {
protected:
    double maxThroughput; // Max theoretical throughput in Mbps

public:
    AccessPoint(double maxTp) : maxThroughput(maxTp) {}
    virtual ~AccessPoint() = default;
    virtual void simulate(const std::vector<User>& users, double packetSizeKB) = 0;
};

#endif // ACCESSPOINT_H