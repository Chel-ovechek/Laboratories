#include "Queue.h"

int main() {
    setlocale(LC_ALL, "");
    Queue<int> q;

    // Проверка вызова pop() при пустой очереди
    try {
        std::cout << "Пытаемся извлечь элемент из пустой очереди..." << std::endl;
        int value = q.pop(); // Это вызовет исключение
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Обработка исключения: " << e.what() << std::endl;
    }

    // Теперь добавим элементы и попробуем снова
    q.push(10);
    q.push(20);
    q.display();

    try {
        std::cout << "Извлечённый элемент: " << q.pop() << std::endl;
        q.display();
        q.pop();
        q.pop(); // Еще раз, чтобы вызвать исключение
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Обработка исключения: " << e.what() << std::endl;
    }
}