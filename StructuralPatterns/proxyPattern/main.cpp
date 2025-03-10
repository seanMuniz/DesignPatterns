#include <iostream>
#include <memory>
#include <string>

// the subject interface
class Database {
    public: 
        virtual void fetchData() = 0; 
        virtual ~Database() = default;
}; 

// The Real Subject
class RealDatabase : public Database {
    public: 
        void fetchData() override {
            std::cout << "Fetching data from the real database ... \n";
        }
};

// The proxy
class DatabaseProxy :public Database {
    private:
        std::shared_ptr<RealDatabase> realDatabase;
    public: 
        void fetchData() override {
            if (!realDatabase) {
                std::cout << "Initializing the real database for the first time...\n";
            }
            std::cout<< "Proxy delegating to the real database... \n";
            realDatabase->fetchData();
        }
};

int main() {
    
    std::shared_ptr<Database>dbProxy = std::make_shared<DatabaseProxy>(); 

    std::cout << "Clients making the first request: \n"; 
    dbProxy->fetchData(); 

    std::cout<< "\n Client making another request: \n";
    dbProxy->fetchData(); 


    return 0; 
}