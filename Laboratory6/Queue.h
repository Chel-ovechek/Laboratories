#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::vector<T> data;

public:
    void push(const T& item) {
        data.push_back(item);
    }

    T pop() {
        if (data.empty()) {
            throw std::out_of_range("Попытка извлечь элемент из пустой очереди");
        }
        T frontItem = data.front();
        data.erase(data.begin());
        return frontItem;
    }

    bool empty() const {
        return data.empty();
    }

    void display() const {
        for (const auto& item : data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};


