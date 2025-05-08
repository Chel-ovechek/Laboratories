#include "User.h"
#include <iostream>
#include <stdexcept> // Добавлено для std::invalid_argument

User::User(const std::string& n, int i, int a) : name(n), id(i), accessLevel(a) {
    if (n.empty()) throw std::invalid_argument("Name cannot be empty");
    if (i < 0) throw std::invalid_argument("ID cannot be negative");
    if (a < 0) throw std::invalid_argument("Access level cannot be negative");
}

std::string User::getName() const { return name; }
int User::getId() const { return id; }
int User::getAccessLevel() const { return accessLevel; }
void User::setName(const std::string& n) {
    if (n.empty()) throw std::invalid_argument("Name cannot be empty");
    name = n;
}
void User::setId(int i) {
    if (i < 0) throw std::invalid_argument("ID cannot be negative");
    id = i;
}
void User::setAccessLevel(int a) {
    if (a < 0) throw std::invalid_argument("Access level cannot be negative");
    accessLevel = a;
}