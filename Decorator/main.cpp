#include <iostream> 
#include <string> 


using namespace std; 

// Interface
class Message {
    public: 
        virtual ~Message() = default; 
        virtual string getContent() const = 0;
};

// Concrete Component
// This is the object that will be wrapped. 
class PlainMessage: public Message {
    private: 
        string content; 
    public: 
        PlainMessage(const string& msg) : content(msg) {}
        string getContent() const override {
            return content;
        }

};

// Base Decorator
class MessageDecorator : public Message {
protected:
    Message* message; // Wraps a Message object

public:
    MessageDecorator(Message* msg) : message(msg) {}
    ~MessageDecorator() {
        delete message;
    }
};

// Concrete Decorator 1: Adds stars around the message
class StarDecorator : public MessageDecorator {
public:
    StarDecorator(Message* msg) : MessageDecorator(msg) {}
    std::string getContent() const override {
        return "*** " + message->getContent() + " ***";
    }
};

// Concrete Decorator 2: Adds a banner around the message
class BannerDecorator : public MessageDecorator {
public:
    BannerDecorator(Message* msg) : MessageDecorator(msg) {}
    std::string getContent() const override {
        return "==== " + message->getContent() + " ====";
    }
};


int main() {

    Message* myMessage = new PlainMessage("Hello World");

    // Decorate with stars
    Message* starMessage = new StarDecorator(myMessage);

    // Decorate with a banner on top of the stars
    Message* bannerMessage = new BannerDecorator(starMessage);

    // Print the final decorated message
    std::cout << bannerMessage->getContent() << std::endl;

    return 0;
}


