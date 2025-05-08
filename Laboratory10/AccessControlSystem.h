#pragma once
#include <vector>
#include <memory>
#include "User.h"
#include "Resource.h"

template<typename T>
class AccessControlSystem {
private:
    std::vector<std::unique_ptr<User>> users;
    std::vector<std::unique_ptr<Resource>> resources;

public:
    void addUser(std::unique_ptr<User> user);
    void addResource(std::unique_ptr<Resource> resource);
    bool checkAccess(const std::string& userName, const std::string& resourceName) const;
    void displayAllUsers() const;
    std::unique_ptr<User> findUserById(int id) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
