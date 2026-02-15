# C++ Ride Sharing System

## Build & Run (CMake)
```bash
cd cpp
mkdir -p build
cd build
cmake ..
cmake --build .
./ride_sharing
```

## Notes
- `Ride` is an abstract base class with a pure virtual `fare()` to demonstrate polymorphism.
- `StandardRide` and `PremiumRide` override `fare()`.
- `Driver` encapsulates `assignedRides` as a private list and exposes `addRide()` and reporting methods.
- `Rider` stores requested rides and prints history.
