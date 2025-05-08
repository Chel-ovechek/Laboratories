#pragma once
#include "User.h"

class Teacher : public User {
private:
    std::string department;

public:
    Teacher(const std::string& n, int i, int a, const std::string& d);
    void displayInfo() const override;
    User* clone() const override; // Реализация клонирования
};

