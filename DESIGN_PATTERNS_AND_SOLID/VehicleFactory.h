//
//  VehicleFactory.h
//  LLD_PARKING_LOT
//
//  Created by Paras Kaushik on 09/07/23.
//

#ifndef VehicleFactory_h
#define VehicleFactory_h
#include <iostream>
#include <string>

// Abstract Base Vehicle class
class Vehicle {
public:
    virtual void drive() const = 0;
    virtual ~Vehicle() {}
};


class Car : public Vehicle {
public:
    void drive() const override {
        std::cout << "Car is driving." << std::endl;
    }
};


class Bike : public Vehicle {
public:
    void drive() const override {
        std::cout << "Bike is driving." << std::endl;
    }
};


class Truck : public Vehicle {
public:
    void drive() const override {
        std::cout << "Truck is driving." << std::endl;
    }
};

// Demonstrating factory design pattern
//class VehicleFactory {
//public:
//    static Vehicle* createVehicle(const std::string& vehicleType) {
//        if (vehicleType == "Car")
//            return new Car();
//        else if (vehicleType == "Bike")
//            return new Bike();
//        else if (vehicleType == "Truck")
//            return new Truck();
//        else
//            return nullptr;
//    }
//};

// ABSTRACT FACTORY CREATES TEMPLATE FOR CREATING FACTORIES THAT IN TURN CREATE OBJECTS
// Abstract Vehicle Brand class(abstract factory)
class VehicleBrandFactory {
public:
    virtual Vehicle* createCar() = 0;
    virtual Vehicle* createBike() = 0;
    virtual Vehicle* createTruck()=0;
};

// Concrete Audi Vehicle Factory
class AudiFactory : public VehicleBrandFactory {
public:
    Vehicle* createCar() override {
        // this car can also be a AudiCar Inheriting from an abstract Car 
        return new Car();
    }

    Vehicle* createBike() override {
        return new Bike();
    }
    
    Vehicle* createTruck() override {
        return new Truck();
    }
    
};

// Concrete BMW Vehicle Brand
class BmwFactory : public VehicleBrandFactory {
public:
    Vehicle* createCar() override {
        return new Car();
    }

    Vehicle* createBike() override {
        return new Bike();
    }
    
    Vehicle* createTruck() override {
        return new Truck();
    }

};
/*
 While using factory design patteern we were directly calling factory
 but here with abstract factory design pattern we have multiple factories
 
 **/

// Main Vehicle Factory - To create brand-specific factories
// even an abstract factory is facilitated by a factory
class VehicleFactory {
public:
    static VehicleBrandFactory* createVehicleBrandFactory(const std::string& brand) {
        if (brand == "Audi")
            return new AudiFactory();
        else if (brand == "BMW")
            return new BmwFactory();
        else
            return nullptr;
    }
};


#endif /* VehicleFactory_h */
