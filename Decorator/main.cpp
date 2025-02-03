#include <iostream> 
#include <string> 
#include <memory>

using namespace std; 

// Interface
class Message {
    public: 
        virtual ~Message() = default; 
        virtual string getContent() const = 0;
};

// Concrete Component
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
    std::shared_ptr<Message> message; // Wraps a Message object

public:
    MessageDecorator(std::shared_ptr<Message> msg) : message(std::move(msg)) {}
};

// Concrete Decorator 1: Adds stars around the message
class StarDecorator : public MessageDecorator {
public:
    StarDecorator(std::shared_ptr<Message> msg) : MessageDecorator(std::move(msg)) {}
    std::string getContent() const override {
        return "*** " + message->getContent() + " ***";
    }
};

// Concrete Decorator 2: Adds a banner around the message
class BannerDecorator : public MessageDecorator {
public:
    BannerDecorator(std::shared_ptr<Message> msg) : MessageDecorator(std::move(msg)) {}
    std::string getContent() const override {
        return "==== " + message->getContent() + " ====";
    }
};


int main() {
    // Base plain message
    std::shared_ptr<Message> myMessage = std::make_shared<PlainMessage>("Hello, World!");

    // Decorate with stars
    std::shared_ptr<Message> starMessage = std::make_shared<StarDecorator>(myMessage);

    // Decorate with a banner on top of the stars
    std::shared_ptr<Message> bannerMessage = std::make_shared<BannerDecorator>(starMessage);

    // Print the final decorated message
    std::cout << bannerMessage->getContent() << std::endl;

    return 0;
}


