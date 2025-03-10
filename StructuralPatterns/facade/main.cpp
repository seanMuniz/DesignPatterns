#include <iostream>

class Light{
    public: 
        void turnOn(){
            std::cout<< "The lights are on" << std::endl;
        }

        void turnOff() {
            std::cout << "The lights are off" << std::endl;
        }
}; 

class TV{
    public:
        void turnOn() {
            std::cout << "The TV is on" <<std::endl;
        }

        void turnOff() {
            std::cout<< "The TV is off" <<std::endl;
        }
};

class MusicSystem {
    public:
        void playMusic() {
            std::cout << "The music is playing" << std::endl;
        }

        void stopMusic() {
            std::cout<< "The music is stopped " << std::endl;
        }
};

class HomeAutomationFacade{
    private:
        Light light; 
        TV tv;
        MusicSystem musicSystem;
    public: 
        void turnEverythingOn(){
            std::cout << "Turning everything ON:\n";
            light.turnOn();
            tv.turnOn();
            musicSystem.playMusic();
        }
        void turnEverythingOff() {
            std::cout << "Turning everything OFF:\n";
            musicSystem.stopMusic();
            tv.turnOff();
            light.turnOff();
        }
};

int main() {
    HomeAutomationFacade home; 
    std::cout << "evening routine" << std::endl;

    home.turnEverythingOn();
    std::cout << "\nNight Routine:\n";
    home.turnEverythingOff(); // Simplified interface to turn everything off

    return 0;
}
