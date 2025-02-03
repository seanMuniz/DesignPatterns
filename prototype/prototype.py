import copy 

#Base Prototype class
class Prototype: 
    def __init__(self): 
        self._objects = {}

    def register(self, name, obj):
        self._objects[name] = obj
    
    def unregister(self, name):
        if name in self._objects:
            del self._objects[name]
    
    def clone(self, name, deep=False):
        obj = self._objects.get(name)
        return copy.deepcopy(obj) if deep else copy.copy(obj)

# Example class to be cloned
class Product:
    def __init__(self, name, price, features=None):
        self.name = name
        self.price = price
        self.features = features or []

    def __str__(self):
        return f"Product(name={self.name}, price={self.price}, features={self.features})"

if __name__ == "__main__":
    # Create a prototype manager
    prototype = Prototype()

    # Create an initial product and register it
    product1 = Product(name="Laptop", price=1200, features=["16GB RAM", "1TB SSD"])
    prototype.register("basic_laptop", product1)

    # Clone the product (shallow copy)
    cloned_product1 = prototype.clone("basic_laptop")
    cloned_product1.name = "Gaming Laptop"
    cloned_product1.features.append("RTX 3080")  # This affects the original in shallow copy

    # Clone the product (deep copy)
    cloned_product2 = prototype.clone("basic_laptop", deep=True)
    cloned_product2.name = "Work Laptop"
    cloned_product2.features.append("Docking Station")  # Does NOT affect the original

    # Display the original and cloned products
    print("Original Product:", product1)
    print("Shallow Cloned Product:", cloned_product1)
    print("Deep Cloned Product:", cloned_product2)
