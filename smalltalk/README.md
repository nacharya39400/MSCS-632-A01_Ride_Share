# Ride Sharing System

## Overview

This project is a simple object oriented Ride Sharing System implemented
in GNU Smalltalk. It demonstrates core OOP concepts including: - Classes
and subclasses - Encapsulation via getters and setters - Inheritance -
Polymorphism (different fare calculations) - Collections - Basic console
output using Transcript

## System Components

### Ride (Base Class)

Represents a generic ride with: - rideID - pickupLocation -
dropoffLocation - distance

Provides: - Fare calculation (base rate) - Formatted rideDetails output

### StandardRide (Subclass of Ride)

Overrides fare calculation: - fare = distance × 1.25

### PremiumRide (Subclass of Ride)

Overrides fare calculation: - fare = (distance × 2.50) + 3.00

### Driver

Represents a driver with: - driverID - name - rating - assigned rides

Provides: - addRide - getDriverInfo

### Rider

Represents a rider with: - riderID - name - requested rides

Provides: - requestRide - viewRides - getRiderInfo

## Demo Behavior

The demo script:

1.  Creates a StandardRide and PremiumRide
2.  Stores rides in a collection
3.  Displays ride details polymorphically
4.  Creates a Driver and assigns rides
5.  Creates a Rider and requests rides
6.  Displays Driver info
7.  Displays Rider ride history

## Requirements

-   GNU Smalltalk

Install (macOS using Homebrew):

    brew install gnu-smalltalk


## How to Run

1.  Open terminal
2.  Navigate to the project directory
3.  Run:

```
    gst RideSharingSystem.st

## Expected Output

Console output showing: - Ride listings - Driver information - Rider
ride history
