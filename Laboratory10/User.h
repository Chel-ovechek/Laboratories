#pragma once
#include <string>
#include <memory>

class User {
protected:
    std::string name;
    int id;
    int accessLevel;

public:
    User(const std::string& n, int i, int a);
    virtual ~User() = default;

    virtual void displayInfo() const = 0;
    virtual User* clone() const = 0; // Виртуальный метод для клонирования

    std::string getName() const;
    int getId() const;
    int getAccessLevel() const;
    void setName(const std::string& n);
    void setId(int i);
    void setAccessLevel(int a);
};