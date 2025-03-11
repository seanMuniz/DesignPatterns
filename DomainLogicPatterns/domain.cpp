#include <iostream>
#include <vector>

using namespace std;

class Product {
private: 
    string name;
    double price;
public: 
    Product(const string& name, double price) : name(name), price(price) {}
    string getName() const {return name;}
    double getPrice() const {return price; }
};

class OrderItem {
private: 
    Product& product; 
    int quantity;
public: 
    OrderItem(Product& product, int quantity) : product(product), quantity(quantity) {}
    double getTotalPrice() const {
        return product.getPrice();
    }
    void display() const {
        cout << quantity << " x " << product.getName() << " @ $ "
            << product.getPrice() << "each = $" << getTotalPrice() << endl;
    }
};

class Order{
private: 
    vector<OrderItem> items;
public: 
    void addItem(Product& product, int quantity) {
        items.emplace_back(product, quantity);
    }
    double getTotalAmount() const {
        double total = 0.0;
        for (const auto& item: items) {
            total += item.getTotalPrice();
        } 
        return total;
    }
    void displayOrder() const {
        cout << "Order Details: \n";
        for (const auto& item: items) {
            item.display();
        }
        cout << "Total order amount $: " << getTotalAmount() << endl;
    }
};

class Customer {
private:
    string name;
    vector<Order> orders;
public: 
    Customer(const string& name) : name(name) {}
    void placeOrder(Order order) {
        orders.push_back(order);
        cout << name << "placed a new order. \n";
    }
    void displayOrders() const {
        cout << "Orders for " <<name<< ":\n";
        for (const auto& order: orders){
            order.displayOrder();
            cout << "-----------------------\n";
        }
    }
};

int main() {
    // Creating products
    Product product1("Laptop", 1200.00);
    Product product2("Mouse", 25.50);
    Product product3("Keyboard", 49.99);

    // Creating a customer
    Customer customer("Alice");

    // Creating an order
    Order order1;
    order1.addItem(product1, 1);
    order1.addItem(product2, 2);

    // Customer places the order
    customer.placeOrder(order1);

    // Creating another order
    Order order2;
    order2.addItem(product3, 1);

    customer.placeOrder(order2);

    // Display all orders for the customer
    customer.displayOrders();
}