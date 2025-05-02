#pragma once
#include <iostream>
#include <vector>
#include <stdexcept> // для исключений

template <typename T>
class Queue {
private:
    std::vector<T> data; // контейнер для хранения элементов
public:
    // Метод добавления элемента в очередь
    void push(const T& item) {
        data.push_back(item);
    }

    // Метод удаления элемента из очереди
    T pop() {
        if (data.empty()) {
            throw std::out_of_range("Очередь пуста");
        }
        T frontItem = data.front();
        data.erase(data.begin());
        return frontItem;
    }

    // Метод для проверки, пуста ли очередь
    bool empty() const {
        return data.empty();
    }

    // Метод для отображения содержимого очереди (по желанию)
    void display() const {
        for (const auto& item : data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

