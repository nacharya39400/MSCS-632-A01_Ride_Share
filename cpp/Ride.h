#ifndef RIDE_H
#define RIDE_H

#include <string>
#include <sstream>
#include <iomanip>

// Base class demonstrating encapsulation (private/protected members + public interface),
// inheritance (subclasses extend Ride), and polymorphism (virtual fare()).
class Ride {
protected:
    int rideID;
    std::string pickupLocation;
    std::string dropoffLocation;
    double distanceMiles; // stored in miles for fare calculation

public:
    Ride(int id,
         std::string pickup,
         std::string dropoff,
         double distance)
        : rideID(id),
          pickupLocation(std::move(pickup)),
          dropoffLocation(std::move(dropoff)),
          distanceMiles(distance) {}

    virtual ~Ride() = default;

    // Polymorphic operation: subclasses override this to compute different fares.
    virtual double fare() const = 0;

    // Common formatting for ride details; uses dynamic dispatch for fare().
    virtual std::string rideDetails() const {
        std::ostringstream out;
        out << "Ride #" << rideID
            << " | " << pickupLocation << " -> " << dropoffLocation
            << " | Distance: " << std::fixed << std::setprecision(2) << distanceMiles << " mi"
            << " | Fare: $" << std::fixed << std::setprecision(2) << fare();
        return out.str();
    }

    // Basic getters (encapsulation: state isn't directly mutable from outside).
    int getRideID() const { return rideID; }
    double getDistanceMiles() const { return distanceMiles; }
    const std::string& getPickupLocation() const { return pickupLocation; }
    const std::string& getDropoffLocation() const { return dropoffLocation; }
};

#endif
