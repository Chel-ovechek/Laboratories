#pragma once
#include "User.h"

class Administrator : public User {
private:
    std::string role;

public:
    Administrator(const std::string& n, int i, int a, const std::string& r);
    void displayInfo() const override;
    User* clone() const override; // Реализация клонирования
};
