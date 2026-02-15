#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include "Ride.h"

// Driver encapsulates assignedRides as a private list.
class Driver {
private:
    int driverID;
    std::string name;
    double rating; // 0.0 - 5.0
    std::vector<std::shared_ptr<Ride>> assignedRides;

public:
    Driver(int id, std::string driverName, double driverRating)
        : driverID(id), name(std::move(driverName)), rating(driverRating) {}

    void addRide(const std::shared_ptr<Ride>& ride) {
        assignedRides.push_back(ride);
    }

    std::string getDriverInfo() const {
        std::ostringstream out;
        out << "Driver #" << driverID
            << " | Name: " << name
            << " | Rating: " << std::fixed << std::setprecision(2) << rating
            << " | Completed rides: " << assignedRides.size();
        return out.str();
    }

    std::string listAssignedRides() const {
        std::ostringstream out;
        out << "Assigned rides for " << name << ":\n";
        for (const auto& r : assignedRides) {
            out << "  - " << r->rideDetails() << "\n";
        }
        return out.str();
    }
};

#endif
