#include <iostream> 
#include <memory>

using namespace std;
class TrafficLight; 

// State Interface
class State {
public: 
    virtual ~State() = default; 
    virtual void change(TrafficLight& light) = 0;
    virtual void showState() const = 0; 
};

// Context
class TrafficLight {
    private: 
        // must store pointer to a State.
        /* A state will be passed to the TrafficLight constructor.
           From here, client can then gain access to changing the states
           via the context (TrafficLight).  
        */

        unique_ptr<State> currentState; 
    public:
        TrafficLight(unique_ptr<State> state) : currentState(std::move(state)){}
        
        void setState(unique_ptr<State> newState) {
            currentState = std::move(newState);
        }

        void change() {
            currentState->change(*this);
        }

        void showState() const {
            currentState->showState();
        }
};

// Concrete States. 
class RedState : public State {
public: 
    // Remember that states are also responsible for changing themseleves. 
    void change(TrafficLight& light) override;
    void showState() const override {
        cout << "Traffic light is red. STOP!" << endl; 
    }
};

class GreenState : public State {
public: 
    void change(TrafficLight& light) override; 
    void showState() const override {
        cout << "Traffic Light is green. GO!" << endl;
    }
};

class YellowState : public State {
public: 
    void change(TrafficLight& light) override;

    void showState() const override {
        cout << "Traffic Light is yellow. SLOW DOWN!" << endl;

    }
};

void RedState::change(TrafficLight& light) {
        cout << "Changing from green to yellow" << endl;
        light.setState(std::make_unique<YellowState>());
}

void GreenState::change(TrafficLight& light){
    cout << "Changing from green to yellow" << endl;
    light.setState(std::make_unique<YellowState>());
}

void YellowState::change(TrafficLight& light){
    cout << "Changing light from yellow to red" << endl;
}


int main() {
    // makes instance of the context. remember the context has a pointer
    // to the a state, in this case the red state. 
    TrafficLight light(make_unique<RedState>());
    
    // Simulating Traffic Light changes
    // client can change the states through the context. 
    for (int i = 0; i < 5; i++) {
        light.showState();
        light.change();
    }

    return 0;

}
