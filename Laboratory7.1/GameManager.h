#pragma once
#include <vector>
#include "Entity.h"

template <typename T>
class GameManager {
public:
    std::vector<T> entities;

    void addEntity(const T& entity) {
        entities.push_back(entity);
    }

    void displayAll() const {
        for (const auto& entity : entities) {
            entity->displayInfo();
        }
    }
};
