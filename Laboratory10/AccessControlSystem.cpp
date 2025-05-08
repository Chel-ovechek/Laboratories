#include "AccessControlSystem.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Student.h"

template<typename T>
void AccessControlSystem<T>::addUser(std::unique_ptr<User> user) {
    users.push_back(std::move(user));
}

template<typename T>
void AccessControlSystem<T>::addResource(std::unique_ptr<Resource> resource) {
    resources.push_back(std::move(resource));
}

template<typename T>
bool AccessControlSystem<T>::checkAccess(const std::string& userName, const std::string& resourceName) const {
    auto userIt = std::find_if(users.begin(), users.end(),
        [&userName](const std::unique_ptr<User>& u) { return u->getName() == userName; });
    if (userIt == users.end()) return false;

    auto resourceIt = std::find_if(resources.begin(), resources.end(),
        [&resourceName](const std::unique_ptr<Resource>& r) { return r->getName() == resourceName; });
    if (resourceIt == resources.end()) return false;

    return (*resourceIt)->checkAccess(**userIt);
}

template<typename T>
void AccessControlSystem<T>::displayAllUsers() const {
    for (const auto& user : users) {
        user->displayInfo();
    }
}

template<typename T>
std::unique_ptr<User> AccessControlSystem<T>::findUserById(int id) const {
    auto it = std::find_if(users.begin(), users.end(),
        [id](const std::unique_ptr<User>& u) { return u->getId() == id; });
    if (it != users.end()) {
        // Возвращаем копию существующего объекта через unique_ptr
        return std::unique_ptr<User>(dynamic_cast<User*>(it->get()->clone())); // Предполагается наличие виртуального clone
    }
    return nullptr;
}

template<typename T>
void AccessControlSystem<T>::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Unable to open file for saving: " + filename);
    for (const auto& user : users) {
        file << user->getName() << "," << user->getId() << "," << user->getAccessLevel() << "\n";
    }
    file.close();
}

template<typename T>
void AccessControlSystem<T>::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Unable to open file for loading: " + filename);
    std::string line;
    while (std::getline(file, line)) {
        std::string name;
        int id, accessLevel;
        size_t pos = 0;

        // Читаем имя до первой запятой
        pos = line.find(",");
        if (pos == std::string::npos) continue;
        name = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Читаем id до следующей запятой
        pos = line.find(",");
        if (pos == std::string::npos) continue;
        id = std::stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Читаем accessLevel
        accessLevel = std::stoi(line);

        addUser(std::make_unique<Student>(name, id, accessLevel, "Group1")); // Пример, можно расширить
    }
    file.close();
}

// Явная инстанциация шаблона для компиляции
template class AccessControlSystem<int>;