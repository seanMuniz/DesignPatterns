#include <string>

class Student{
    std::string m_name; 
    int m_id; 
public: 
    Student();
    Student(std::string name, int id);
    void displayInfo() const; 
};

class Course{
    std::string m_name; 
    std::string m_code;
    Student* m_students;
    int m_numStudents;
public: 
    Course(std::string name, std::string code); 
    ~Course();
    void addStudent(Student*); 
    void displayStudents() const; 
};