#include "Student.h"
#include <iostream>

Student::Student(const std::string& n, int i, int a, const std::string& g)
    : User(n, i, a), group(g) {}

void Student::displayInfo() const {
    std::cout << "Student: " << name << ", ID: " << id
        << ", Access Level: " << accessLevel << ", Group: " << group << std::endl;
}

User* Student::clone() const {
    return new Student(*this); // Создаем копию текущего объекта
}