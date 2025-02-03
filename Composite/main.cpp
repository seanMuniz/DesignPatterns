#include <iostream>
#include <vector> 
#include <memory>

// Base Component INTERFACE
class Component {
    public:
        virtual void show() const = 0; // Pure virtual method
        virtual ~Component() = default;
};

class Leaf : public Component {
private:
    std::string name;
public:
    explicit Leaf(const std::string& name) : name(name) {}
    void show() const override {
        std::cout << name << std::endl;
    }
};

class Composite : public Component {
    private:
        std::vector<std::shared_ptr<Component>> children; // pointer to child components
    public: 
        void add(const std::shared_ptr<Component>& component) {
            children.push_back(component); 
        }

        void show() const override {
            for (const auto& child : children){
                child->show();
            }
        }

};

int main(){
    // Create leaf components
    auto leaf1 = std::make_shared<Leaf>("Leaf 1");
    auto leaf2 = std::make_shared<Leaf>("Leaf 2");

    // Create a composite component
    auto composite = std::make_shared<Composite>();
    composite->add(leaf1);
    composite->add(leaf2);

    // Create a larger composite
    auto root = std::make_shared<Composite>();
    root->add(composite);
    root->add(std::make_shared<Leaf>("Leaf 3"));

    // Display the hierarchy
    root->show();

}
