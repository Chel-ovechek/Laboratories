#include "Queue.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "");

    // Очередь для чисел
    Queue<int> intQueue;
    intQueue.push(1);
    intQueue.push(2);
    intQueue.push(3);
    std::cout << "Очередь чисел: ";
    intQueue.display();

    std::cout << "Извлечённый элемент: " << intQueue.pop() << std::endl;
    std::cout << "После удаления: ";
    intQueue.display();

    // Очередь для строк
    Queue<std::string> strQueue;
    strQueue.push("привет");
    strQueue.push("мир");
    std::cout << "Очередь строк: ";
    strQueue.display();

    std::cout << "Извлечённый элемент: " << strQueue.pop() << std::endl;
    std::cout << "После удаления: ";
    strQueue.display();

    return 0;
}

