#ifndef USER_H
#define USER_H

class User {
public:
    int id;            // User ID (only needed for WiFi 4 simulations)
    double dataRate;   // Mbps

    User(int userId = 0, double rate = 10.0) : id(userId), dataRate(rate) {}
    double getDataRate() const { return dataRate; }
    void setDataRate(double rate) { dataRate = rate; }
};

#endif // USER_H
