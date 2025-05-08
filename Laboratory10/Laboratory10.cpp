#include "AccessControlSystem.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"
#include "Resource.h"
#include <iostream>

int main() {
    try {
        AccessControlSystem<int> system;

        system.addUser(std::make_unique<Student>("Alice", 1, 1, "CS101"));
        system.addUser(std::make_unique<Teacher>("Bob", 2, 3, "Computer Science"));
        system.addUser(std::make_unique<Administrator>("Charlie", 3, 5, "Head Admin"));

        system.addResource(std::make_unique<Resource>("Lab", 2));
        system.addResource(std::make_unique<Resource>("Library", 1));

        system.displayAllUsers();

        std::cout << "Access to Lab for Alice: " << (system.checkAccess("Alice", "Lab") ? "Granted" : "Denied") << std::endl;
        std::cout << "Access to Library for Bob: " << (system.checkAccess("Bob", "Library") ? "Granted" : "Denied") << std::endl;

        system.saveToFile("users.txt");
        AccessControlSystem<int> loadedSystem;
        loadedSystem.loadFromFile("users.txt");
        loadedSystem.displayAllUsers();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}