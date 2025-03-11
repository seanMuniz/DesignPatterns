#include <iostream> 
#include <vector>

using namespace std;

// Domain model (represents a user)
class User {
public: 
    int id; 
    string name;
    string email; 
    User(int id, string name, string email)
    : id(id), name(name), email(email) {}
};

class UserRepository {
private: 
    vector<User> users;
public: 
    void addUser(const User& user) {
        users.push_back(user);
    }
    User* findUserById(int id) {
        for (auto& user : users){
            if(user.id == id){
                return &user;
            }
        }
    }
    const vector<User>& getAllUsers() const {
        return users;
    }
};

// service layer (handles business logic)
class UserService {
private: 
    UserRepository& userRepository;
public: 
    UserService(UserRepository& repo) : userRepository(repo){}

    void registerUser(int id, const string name, string email) {
        if (userRepository.findUserById(id )){
            cout << "Error, user already exists\n";
            return;
        }
        userRepository.addUser(User(id, name, email));
        cout << "User registered successfully!";
    }

    void getUserDetails(int id) {
        User* user = userRepository.findUserById(id);
        if (user) {
            cout << "User id: " << user->id << endl;
            cout << "Name: " << user->name << endl;
            cout << "email: " << user->email << endl;
        } else {
            cout << "user not found";
        }
    }
};