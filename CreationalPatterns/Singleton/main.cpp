#include <iostream>

class Random{
private: 
    Random() {}
    
    Random(const Random&) = delete;

    const float m_randomGenerator = 0.5f;

    static Random* s_Instance; 

public: 

    static Random* Get() {
        // This will return the static instance of Random. 
         if (s_Instance == nullptr) {
            s_Instance = new Random;
         }
         return s_Instance;
    }

    float Float() { 
        std::cout << "Creating random number..." << std::endl;    
        
        return m_randomGenerator ;
    }
};

Random* Random::s_Instance = nullptr; 


int main() {

    // get will return the static instance of Random. 
    // since it is being returned, we can then used it to call float. 
    // float will then return the random number which we will then use 
    // to assign to number

    float number = Random::Get()->Float();
    std::cout << number;
}