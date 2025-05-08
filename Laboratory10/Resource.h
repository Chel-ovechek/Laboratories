#pragma once
#include <string>
#include "User.h"

class Resource {
private:
    std::string name;
    int requiredAccessLevel;

public:
    Resource(const std::string& n, int a);
    bool checkAccess(const User& user) const;
    std::string getName() const;
    int getRequiredAccessLevel() const;
};

