#pragma once
#include "User.h"

class Student : public User {
private:
    std::string group;

public:
    Student(const std::string& n, int i, int a, const std::string& g);
    void displayInfo() const override;
    User* clone() const override; // Реализация клонирования
};

