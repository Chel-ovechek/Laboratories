#include "Administrator.h"
#include <iostream>

Administrator::Administrator(const std::string& n, int i, int a, const std::string& r)
    : User(n, i, a), role(r) {}

void Administrator::displayInfo() const {
    std::cout << "Administrator: " << name << ", ID: " << id
        << ", Access Level: " << accessLevel << ", Role: " << role << std::endl;
}

User* Administrator::clone() const {
    return new Administrator(*this); // Создаем копию текущего объекта
}