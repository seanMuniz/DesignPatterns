#include <iostream>

// interface
class Transport {
    public: 
    virtual void deliver() const = 0;
    virtual ~Transport() {}
};

// concrete class
class Truck: public Transport{
    public:
    void deliver() const override{
        std::cout << "Delivering by truck" << std::endl;
    }
};

// concrete class
class Ship : public Transport {
    public: 
    void deliver() const override{
        std::cout << "Delivering by ship" << std::endl;
    }
};

// creator
class TransportCreator {
    public: 
    virtual Transport* createTransport() const = 0;
    virtual ~TransportCreator() {}

};

// Truck factory
class TruckTransport : public TransportCreator {
    Transport* createTransport() const override {
        return new Truck();
    }
}; 

// Ship factory
class ShipTransport : public TransportCreator {
    Transport* createTransport() const override {
        return new Ship();
    }
};

int main() {
 TransportCreator* transportCreator; // Creator
    Transport* transport; // interface

    /*
        Create a factory for a truck. Use the factory
        to create a Truck object. Then invoke its deliver()
        function. 
    */
    
    // instantiates a TruckTransport (truck factory)
    transportCreator = new TruckTransport(); 

     // the createTransport() function returns a pointer to a TruckTransport
     // transport stores a pointer of TruckTransport
    transport = transportCreator->createTransport();
    
    // the deliver() function from TruckTransport is called.
    transport->deliver();  
    delete transport;
    delete transportCreator;

    /*
        create a factory for a ship. Use the factory 
        to create a ship object. Then invoke its deliver()
        function.
    */

    transportCreator = new ShipTransport();
    transport = transportCreator->createTransport();
    transport->deliver();
    delete transport;
    delete transportCreator;



}
