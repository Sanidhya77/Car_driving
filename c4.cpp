#include <iostream>
#include <string>

using namespace std;

//  Car class
class Car {
 private:
    string brand;
    string model;
    int year;
    bool engineRunning;
    int mileage;   
    double fuel;   
    int speed;
    bool sportmode;

    const double fuelrate = 10; 
    const int fueltank = 100;
    const int maxspeed = 200;
    const int sportmodemaxspeed = 300;

public:
    // Constructor
    Car(string b, string m, int y, double infuel)
        : brand(b), model(m), year(y), engineRunning(false), mileage(0), fuel(infuel), speed(0), sportmode(false) {}

    // Method to start the engine
    void startEngine() {
        if (!engineRunning) {
            if (fuel > 0) {
                engineRunning = true;
                cout << "The engine of " << brand << " " << model << " is now running." << endl;
            } else {
                cout << "No fuel cannot start teh engine" << endl;
            }
        } else {
            cout << "The engine is already running!" << endl;
        }
    }

    // Method to stop the engine
    void stopEngine() {
        if (engineRunning) {
            if (speed == 0) {
            engineRunning = false;
            cout << "The engine of " << brand << " " << model << " is now stopped." << endl;
            } else {
                cout << "The car is still moving, cannot stop the engine!" << endl;
            } 
        }else {
                  cout << "The engine is already off!" << endl;
            }
        }
    

    // Method to honk the horn
    void honk() const {
        cout << brand << " " << model << " honks: h  h h h h h h h h " << endl;
    }

    // Method to drive the car
    void drive(int kilom) {
        if (!engineRunning) {
            cout << "You need to start the engine first!" << endl;
            return;
        }
        double adjfuelrate = sportmode ? fuelrate * 0.5 : fuelrate; 

        double need = kilom / adjfuelrate;

        if (fuel >= need) {
            mileage += kilom;
            fuel -= need;
            cout << "The car drove " << kilom << " km. Total mileage: " << mileage 
                 << " km. Fuel left: " << fuel << " liters." << endl;
        } else {
            cout << "Not enough fuel to drive " << kilom << " km. Please refuel!" << endl;
        }
    }

    // Method to refuel the car
    void refuel(double liters) {
        if (fuel + liters > fueltank) {
            cout << "Cannot refuel beyond " << fueltank<< " liters! Adding only " 
                 << (fueltank- fuel) << " liters." << endl;
            fuel = fueltank;
        } else {
            fuel += liters;
            cout << "Refueled " << liters << " liters. Current fuel level: " << fuel << " liters." << endl;
        }
    }

 // Method to accelerate the car
 void accelerate(int increase) {
    if (!engineRunning) {
        cout << "Start the engine first before accelerating!" << endl;
        return;
    }
    int fullspeed = sportmode ? sportmodemaxspeed : maxspeed;
         
    if (speed + increase > fullspeed) {
        speed = fullspeed;
        cout << "Car has reached its max speed of sports mode " << fullspeed << " km/h!" << endl;
    } else {
        speed += increase;
        cout << "Car accelerated. Current speed: " << speed << " km/h." << endl;
    }
} 
     // Method to brake
     void brake(int decrease) {
        if (speed - decrease < 0) {
            speed = 0;
            cout << "Car has completely stopped." << endl;
        } else {
            speed -= decrease;
            cout << "Car slowed down. Current speed: " << speed << " km/h." << endl;
        }
     }    
     void getsportmode() {
        sportmode = !sportmode;
        if (sportmode) {
            cout << "Sports mode activated. Max speed is now " << sportmodemaxspeed << " km/h." << endl;
        } else {
            cout << "Sports mode deactivated. Max speed is back to " << maxspeed << " km/h." << endl;
        }
    }

    // Method to display car details
    void displayInfo() const {
        cout << "Car: " << brand << " " << model << " (" << year << ") | Mileage: " 
             << mileage << " km | Fuel Level: " << fuel << " liters | Speed: " << speed << " km/h" << endl;
    }

};

int main() {
    
    Car myCar("Toyota", "Supra", 2020, 70);

    // Displaying car details
    myCar.displayInfo();

    
    myCar.drive(30);
    myCar.startEngine();
    myCar.honk();
    myCar.accelerate(120);
    myCar.drive(20);
    myCar.getsportmode();
    myCar.accelerate(300);
    myCar.drive(50);
    myCar.brake(300);
    myCar.refuel(30);
    myCar.getsportmode();
    myCar.accelerate(290);
    myCar.drive(70);
    myCar.brake(290);


    myCar.stopEngine();
    myCar.displayInfo();

    return 0;
}


