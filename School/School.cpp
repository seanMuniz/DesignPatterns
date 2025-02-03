#include <iostream> 
#include "School.h"
Student::Student() {};
Student::Student(std::string name, int id){
    m_name = name;
    m_id = id;
}

void Student::displayInfo() const {
    std::cout << "Student Name: " << m_name << std::endl; 
    std::cout << "Student ID: " << m_id << std::endl; 
    std::cout << '\n'; 
}

Course::Course(std::string name, std::string code){
    m_name = name;
    m_code = code;
    m_numStudents = 0;
}

void Course::addStudent(Student* newStudent) {
    m_numStudents++; 
    
    Student* students = new Student[m_numStudents];

    for (int i = 0 ; i < m_numStudents; i++){
        students[i] = m_students[i];
    }

    m_students = students; 

}

void Course::displayStudents() const {
    std::cout<< "List of all the students" << std::endl;
    for (int i = 0 ; i < m_numStudents ; i++){
        m_students[i].displayInfo();
    }
}
Course::~Course(){
    if (m_students!= nullptr) {
        delete [] m_students;

    }
}