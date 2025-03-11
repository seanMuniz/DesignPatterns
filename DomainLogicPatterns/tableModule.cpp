#include <iostream> 
#include <string>
#include <vector>
using namespace std;

// this is supposed to represent a row.
struct Order {
    int id; 
    string customerName; 
    double totalAmount; 

    Order(int id, const string& name, double amount) 
    : id(id), customerName(name), totalAmount(amount) {}
};

class OrderTable{
private:
    vector<Order> orders; // represents a table as it is a collection of rows. 
public: 
    void addOrder(int id, string name, double totalAmount) {
        orders.emplace_back(id, name, totalAmount);
    }
    Order* getOrderById(int id) {
        for (auto& order: orders){
            if (order.id == id)
                return &order;
        }
        return nullptr;
    }
    bool updateOrderAmount(int id, double newAmount){
        Order* order = getOrderById(id);
        if (order) {
            order->totalAmount =newAmount;
            return true;
        }
        return false;
    }
    bool deleteOrder(int id) {
        for (int i = 0 ; i < orders.size() ; ++ i) {
            if (orders[i].id == id) {
                for (int j = i ; j < orders.size() -1 ; ++ j) {
                    orders[j] = orders[j + 1];
                }
                orders.pop_back();
                return true;
            }
        }
        return false;
    }
    double getTotalRevenue() const {
        double total = 0.0;
        for (int i =0 ; i < orders.size() ; i++){
            total += orders[i].totalAmount;
        }
        return total;
    }
    void displayOrders() const {
        cout << "Order List \n";
        for (int i = 0 ; i < orders.size() ; i++ ){
            cout << "ID: " << orders[i].id << ", Customer: " << orders[i].customerName 
                << ", Total: " << orders[i].totalAmount << "\n";
        }
        cout << "--------------------------\n";
    }
};

int main() {
    OrderTable orderTable; 

    orderTable.addOrder(1, "Alice", 250.99);
    orderTable.addOrder(2, "Camille", 134.99);
    orderTable.addOrder(3, "Mark", 782.12);

    orderTable.displayOrders();

    // Updating an order
    if (orderTable.updateOrderAmount(2, 150.00)) {
        std::cout << "Order updated successfully!\n";
    }

    // Displaying updated orders
    orderTable.displayOrders();

    // Deleting an order
    if (orderTable.deleteOrder(1)) {
        std::cout << "Order deleted successfully!\n";
    }

    // Displaying final orders
    orderTable.displayOrders();

    // Display total revenue
    std::cout << "Total Revenue: $" << orderTable.getTotalRevenue() << "\n";
}
