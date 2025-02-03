#include <iostream>
#include "School.h"

int main() {
    Course c1("Math", "MPM 123");
    Course c2("English", "ENG 101");
    Course c3("Science", "SCI 323");

    Student s1("Sean", 123);
    Student s2("Linh", 213);
    Student s3("Cris", 555);

    c1.addStudent(&s1);
    c1.addStudent(&s2);
    c1.addStudent(&s3);

    c1.displayStudents();
}