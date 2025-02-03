#include <iostream> 

using namespace std;

// Abstract Class (Template)
class Drink {
public: 
    void prepare() {
        boilWater();
        brew(); 
        pourInCup();
    }

protected:
    void boilWater() {
        cout << "Boiling Water" << endl;
    }

    virtual void brew() = 0;

    void pourInCup() {
        cout << "Pouring into cup" << endl; 
    }

    virtual ~Drink() = default;
}; 

// Concrete Class 1: Tea

class Tea: public Drink {
protected: 
    void brew() override {
        cout << "Steeping the tea" << endl;
    }
};

class Coffee : public Drink {
    void brew() override {
        cout << "Drinking coffee" << endl;
    }
}; 

int main() {
    Tea tea; 
    Coffee coffee; 
    cout << "Making Tea: \n"; 
    tea.prepare(); 

    cout << "Making Coddee" << endl; 
    coffee.prepare(); 

    return 0; 
}

