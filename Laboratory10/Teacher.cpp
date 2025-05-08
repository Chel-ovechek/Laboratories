#include "Teacher.h"
#include <iostream>

Teacher::Teacher(const std::string& n, int i, int a, const std::string& d)
    : User(n, i, a), department(d) {}

void Teacher::displayInfo() const {
    std::cout << "Teacher: " << name << ", ID: " << id
        << ", Access Level: " << accessLevel << ", Department: " << department << std::endl;
}

User* Teacher::clone() const {
    return new Teacher(*this); // Создаем копию текущего объекта
}