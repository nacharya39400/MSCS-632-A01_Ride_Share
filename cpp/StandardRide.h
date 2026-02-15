#ifndef STANDARD_RIDE_H
#define STANDARD_RIDE_H

#include "Ride.h"

// StandardRide overrides fare() with standard pricing.
class StandardRide : public Ride {
private:
    double baseFee;
    double perMileRate;

public:
    StandardRide(int id,
                 std::string pickup,
                 std::string dropoff,
                 double distance,
                 double baseFee_ = 2.50,
                 double perMileRate_ = 1.80)
        : Ride(id, std::move(pickup), std::move(dropoff), distance),
          baseFee(baseFee_),
          perMileRate(perMileRate_) {}

    double fare() const override {
        return baseFee + (perMileRate * distanceMiles);
    }
};

#endif
