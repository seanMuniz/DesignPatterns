#include <iostream>
#include <memory>

using namespace std;
// Strategy Interface
class PaymentStrategy {
public: 
    virtual void pay(int amount) = 0; 
    virtual ~PaymentStrategy() = default;
};

// Concrete Strategy 1: Credit Card Payment
class CreditCardPayment : public PaymentStrategy {
public: 
    void pay(int amount) override {
        cout << "Paid $" << amount << "using Credit Card" << endl;
    }
};

class PayPalPayment : public PaymentStrategy {
public: 
    void pay(int amount) override {
        cout << "Paid $" << amount << "Using Pay Pal" << endl;
    }
};

// Context. This will keep an insteance 
class ShoppingCart {
private: 
    unique_ptr<PaymentStrategy> paymentStrategy;

public: 
    void setPaymentStrategy(unique_ptr<PaymentStrategy> strategy) {
        paymentStrategy = move(strategy);
    }

    void checkout(int amount){
        if (paymentStrategy) {
            paymentStrategy->pay(amount);
        } else {
            cout << "No payment method selected" << endl;
        }
    }
};

int main() {
    ShoppingCart cart;

    cart.setPaymentStrategy(make_unique<CreditCardPayment>());
    cart.checkout(100);

    cart.setPaymentStrategy(make_unique<PayPalPayment>());
    cart.checkout(50); 

    return 0;
}