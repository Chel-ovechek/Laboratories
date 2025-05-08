#include "Resource.h"
#include <stdexcept> // Добавлено для std::invalid_argument

Resource::Resource(const std::string& n, int a) : name(n), requiredAccessLevel(a) {
    if (n.empty()) throw std::invalid_argument("Resource name cannot be empty");
    if (a < 0) throw std::invalid_argument("Required access level cannot be negative");
}

bool Resource::checkAccess(const User& user) const {
    return user.getAccessLevel() >= requiredAccessLevel;
}

std::string Resource::getName() const { return name; }
int Resource::getRequiredAccessLevel() const { return requiredAccessLevel; }