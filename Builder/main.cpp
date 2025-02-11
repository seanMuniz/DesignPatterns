#include <iostream>
#include <string>

using namespace std;
/*
    Car and manual defines the final structure of the product
    This is necessary as the Builders for the car and manual 
    are not to define what the Car and manual are. they are 
    simply to build the object. 
*/
class Car {
private:
    int seats; 
    string engine; 
    bool tripComputer; 
    bool gps;
public: 
    void setSeats(int num) {
        seats = num; 
    }

    void setEngine(const string& eng) {
        engine = eng;
    }

    void setTripComputer(bool tc){
        tripComputer = tc;
    }

    void setGPS(bool g){
        gps = g;
    }

    void showCar() const{
        cout << "Number of seats: " << seats << endl;
        cout << "Engine: " << engine << endl;
        cout << "Has Trip Computer? " << tripComputer << endl;
        cout << "Has GPS? " << gps << endl;
    }
};

class Manual{
private: 
    string instructions;
public: 
    void addInstruction(const string& ins){
        instructions += ins + "\n";
    }

    void showManual() const {
        cout << "Car Manual: \n" << instructions << endl;
    }
};


// Builder interface
class Builder {
public:
    virtual void reset() = 0;
    virtual void setSeats(int number) = 0;
    virtual void setEngine(const std::string& engine) = 0;
    virtual void setTripComputer() = 0;
    virtual void setGPS() = 0;
    virtual ~Builder() {}
};

/*
    CarBuilder and CarManualBuilder are the concrete builders that implement the
    functionality of the Builder interface. This ensures that all builders 
    follow the same steps. 
*/
class CarBuilder : public Builder {
private: 
    Car* car;
public: 
    CarBuilder() {
        car = new Car();
    }
    ~CarBuilder() {
        delete car;
    }
    void reset() override {
        delete car ; 
        car = new Car();
    }
    void setSeats(int num) override {
        car->setSeats(num);
    }   
    void setEngine(const string& engine) override {
        car->setEngine(engine);
    }
    void setTripComputer() override {
        car->setTripComputer(true);
    }
    void setGPS() override {
        car->setGPS(true);
    }

    Car* getResult() {
        return car;
    }
};

class CarManualBuilder: public Builder{
private: 
    Manual* manual; 
public: 
    CarManualBuilder() { 
        manual = new Manual(); 
    }
    ~CarManualBuilder() { 
        delete manual; 
    }

    void reset() override {
        delete manual;
        manual = new Manual();
    }

    void setSeats(int number) override {
        manual->addInstruction("Seats: " + std::to_string(number));
    }

    void setEngine(const std::string& engine) override {
        manual->addInstruction("Engine: " + engine);
    }

    void setTripComputer() override {
        manual->addInstruction("Trip Computer: Included");
    }

    void setGPS() override {
        manual->addInstruction("GPS: Included");
    }

    Manual* getResult() {
        return manual;
    }
};

/*
    This class orchastrates the construction of the Car and 
    CarManualBuilder objects. The makeSportsCar and makeSUV functions
    take a Builder object as a parameter. Depending on the type of 
    Builder that is passed, it will execute the functions within 
    the definition in accordance to the passed builder. 
*/
class Director {
public:
    void makeSportsCar(Builder& builder) {
        builder.reset();
        builder.setSeats(2);
        builder.setEngine("Sport Engine");
        builder.setTripComputer();
        builder.setGPS();
    }
    
    void makeSUV(Builder& builder) {
        builder.reset();
        builder.setSeats(5);
        builder.setEngine("SUV Engine");
        builder.setGPS();
    }
};
    
int main() {
    Director director;

    // Create a Sports Car
    CarBuilder carBuilder;
    
    // Remember, this will call upon all the functions necessary for building
    // a car. 
    director.makeSportsCar(carBuilder);

    Car* sportsCar = carBuilder.getResult();
    
    sportsCar->showCar();
    

    // Create a Car Manual for a Sports Car
    CarManualBuilder manualBuilder;
    
    director.makeSportsCar(manualBuilder);
    
    Manual* sportsCarManual = manualBuilder.getResult();
    
    sportsCarManual->showManual();
    

    return 0;
}