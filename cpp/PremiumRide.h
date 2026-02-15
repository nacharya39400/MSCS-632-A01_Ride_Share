#ifndef PREMIUM_RIDE_H
#define PREMIUM_RIDE_H

#include "Ride.h"

// PremiumRide overrides fare() with higher pricing and an optional service fee.
class PremiumRide : public Ride {
private:
    double baseFee;
    double perMileRate;
    double serviceFee;

public:
    PremiumRide(int id,
                std::string pickup,
                std::string dropoff,
                double distance,
                double baseFee_ = 5.00,
                double perMileRate_ = 3.25,
                double serviceFee_ = 1.50)
        : Ride(id, std::move(pickup), std::move(dropoff), distance),
          baseFee(baseFee_),
          perMileRate(perMileRate_),
          serviceFee(serviceFee_) {}

    double fare() const override {
        return baseFee + serviceFee + (perMileRate * distanceMiles);
    }
};

#endif
