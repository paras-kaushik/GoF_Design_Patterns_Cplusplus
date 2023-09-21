//
//  Observable.h
//  LLD_PARKING_LOT
//
//  Created by Paras Kaushik on 16/07/23.
//

#ifndef Observable_h
#define Observable_h

#include <iostream>
#include <vector>
#include <algorithm>

// Observer interface
class Observer {
public:
    virtual ~Observer() {}
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Concrete observer (Display)
class Display : public Observer {
private:
    float temperature;
    float humidity;
    float pressure;
    int displayNumber;
public:
    static int displayNumberCount;
    Display(){
        displayNumber=displayNumberCount;
        displayNumberCount++;
    }
    
    void update(float temperature, float humidity, float pressure) override {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        display();
    }

    void display() {
        std::cout<<this->displayNumber<<" " << "Current conditions: " << temperature << "C, " << humidity << "% humidity, " << pressure << "hPa\n";
    }
};
int Display::displayNumberCount=0;// like a global variable but actually static










// Subject (Observable) interface
class Subject {
protected:
    std::vector<Observer*> observers;

public:
    virtual ~Subject() {}
    virtual void registerObserver(Observer* observer) = 0;//subscribe
    virtual void removeObserver(Observer* observer) = 0;// unsubscribe
    virtual void notifyObservers() = 0;//loops over observers and sends update to each
};

// Concrete subject (Weather Station)
class WeatherStation : public Subject {
private:
    float temperature;
    float humidity;
    float pressure;

public:
    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float temperature, float humidity, float pressure) {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }

private:
    void measurementsChanged() {
        notifyObservers();
    }
};


#endif /* Observable_h */
