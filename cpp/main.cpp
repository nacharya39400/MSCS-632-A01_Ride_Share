#include <iostream>
#include <vector>
#include <memory>

#include "StandardRide.h"
#include "PremiumRide.h"
#include "Driver.h"
#include "Rider.h"

int main() {
    // Create rides of different types (inheritance + polymorphism)
    std::shared_ptr<Ride> r1 = std::make_shared<StandardRide>(
        101, "Downtown", "Airport", 12.4);
    std::shared_ptr<Ride> r2 = std::make_shared<PremiumRide>(
        102, "University", "Stadium", 4.7);
    std::shared_ptr<Ride> r3 = std::make_shared<StandardRide>(
        103, "Mall", "Home", 8.1);

    // Polymorphic list
    std::vector<std::shared_ptr<Ride>> rides = { r1, r2, r3 };

    std::cout << "=== Polymorphic Ride List ===\n";
    for (const auto& ride : rides) {
        // Calls the correct overridden fare() via dynamic dispatch
        std::cout << ride->rideDetails() << "\n";
    }
    std::cout << "\n";

    // Driver and Rider usage
    Driver d1(1, "Alex Driver", 4.92);
    Rider u1(10, "Sam Rider");

    // Request and assign rides
    u1.requestRide(r1);
    u1.requestRide(r2);
    u1.requestRide(r3);

    d1.addRide(r1);
    d1.addRide(r2);

    std::cout << "=== Driver Info ===\n";
    std::cout << d1.getDriverInfo() << "\n";
    std::cout << d1.listAssignedRides() << "\n";

    std::cout << "=== Rider Info ===\n";
    std::cout << u1.getRiderInfo() << "\n";
    std::cout << u1.viewRides() << "\n";

    return 0;
}
