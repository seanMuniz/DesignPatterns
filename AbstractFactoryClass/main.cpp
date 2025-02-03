#include <iostream> 
#include <string> 

//Abstract product A
class Car{
    public: 
        virtual void drive() const = 0; 
}; 

// Abstract product B
class MotorCycle {
    public: 
        virtual void ride() const = 0; 
}; 

//concrete product A1
class HondaCar : public Car{
    public: 
        void drive() const override {
            std::cout << "Driving a Honda Car!" << std::endl; 
        }
};

//concrete product A2
class ToyotaCar : public Car {
    public: 
        void drive() const override {
            std::cout << "Driving a Toyota car!" << std::endl; 
        }
}; 

//concrete product B1
class HondaMotorCycle : public MotorCycle {
    public: 
        void ride() const override {
            std::cout << "Driving a Kawasaki motorcycle" << std::endl; 
        }
}; 

//concrete product B2
class ToyotaMotorCycle : public MotorCycle {
    public: 
        void ride() const override {
            std::cout << "Driving a Harley motorcycle" << std::endl; 
        }
}; 


// Abstract Factory 

class VehicleFactory {
    public: 
        virtual Car* createCar() const = 0; 
        virtual MotorCycle* createMotorCycle() const = 0; 
}; 

class HondaFactory : public VehicleFactory {
    public: 
        Car* createCar() const override {
            return new HondaCar(); 
        }

        MotorCycle* createMotorCycle() const override {
            return new HondaMotorCycle();
        }
};

class ToyotaFactory: public VehicleFactory {
    public: 
        Car* createCar() const override {
            return new ToyotaCar(); 
        }

        MotorCycle* createMotorCycle() const override {
            return new ToyotaMotorCycle(); 
        }
};

int main() {

    // we are making a factory but ensuring that it is a Honda Factory. 
    VehicleFactory* factory = new HondaFactory(); 

    // We now use the honda factory to create a car and a motorcycle. 
    Car* car = factory->createCar(); 
    MotorCycle* MotorCycle = factory->createMotorCycle(); 

    car->drive(); 
    MotorCycle->ride(); 
}





