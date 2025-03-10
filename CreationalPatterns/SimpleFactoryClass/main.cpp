#include <iostream> 
#include <string>

class Vehicle {
    public: 
        virtual void drive() const = 0; // pur virtual funciton.

}; 

class Honda : public Vehicle{
    void drive() const override {
        std::cout << "Vroom! I'm a Honda!" << std::endl; 
    }
    ~Honda() {
        std::cout << "In Honda destructor" << std::endl; 
    }
}; 

 class Toyota : public Vehicle {
    void drive() const override {
        std::cout<< "Kapow! I'm a Toyota!" << std::endl; 
    }
    ~Toyota() {
        std::cout << "In Toyota destructor" << std::endl; 
    }
 };

 class Ford: public Vehicle{
    void drive () const override {
        std::cout << "Blaow! I'm a Ford!" << std::endl; 
    }
    ~Ford() {
        std::cout << "In Ford destructor" << std::endl; 
    }
 }; 

 class CarFactory{
public: 
    Vehicle* createInstance(std::string carType){
        if (carType == "Honda"){
            return new Honda;
        } else if (carType == "Toyota"){
            return new Toyota; 
        } else if (carType == "Ford"){
            return new Ford; 
        } else {
            return nullptr; 
        }
    }
};

 int main() {

    CarFactory carFactory; 

    Vehicle* honda = carFactory.createInstance("Honda"); 

    honda->drive();

    Vehicle* toyota = carFactory.createInstance("Toyota"); 

    toyota->drive(); 

    Vehicle* ford = carFactory.createInstance("Ford");

    ford->drive(); 

 }