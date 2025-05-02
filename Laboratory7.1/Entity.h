#pragma once
#include <string>

class Entity {
public:
    virtual ~Entity() {}
    virtual void displayInfo() const = 0;
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string& data) = 0;
};

