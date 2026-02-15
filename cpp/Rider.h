#ifndef RIDER_H
#define RIDER_H

#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Ride.h"

class Rider {
private:
    int riderID;
    std::string name;
    std::vector<std::shared_ptr<Ride>> requestedRides;

public:
    Rider(int id, std::string riderName)
        : riderID(id), name(std::move(riderName)) {}

    void requestRide(const std::shared_ptr<Ride>& ride) {
        requestedRides.push_back(ride);
    }

    std::string getRiderInfo() const {
        std::ostringstream out;
        out << "Rider #" << riderID << " | Name: " << name
            << " | Requested rides: " << requestedRides.size();
        return out.str();
    }

    std::string viewRides() const {
        std::ostringstream out;
        out << "Ride history for " << name << ":\n";
        for (const auto& r : requestedRides) {
            out << "  - " << r->rideDetails() << "\n";
        }
        return out.str();
    }
};

#endif
