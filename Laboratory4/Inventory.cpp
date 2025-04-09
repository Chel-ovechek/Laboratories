#include "Inventory.h"

Inventory::Inventory() {
    n = 0;  // Явная инициализация
    inventory = nullptr;
}

void Inventory::addItem(const std::string& item) {
    n += 1;  // Увеличиваем размер

  // Создаем новый массив с новым размером
    std::unique_ptr<std::string[]> newInventory(new std::string[n]);

    // Копируем старые элементы
    for (int i = 0; i < n - 1; i++) {
        newInventory[i] = inventory[i];
    }

    // Добавляем новый элемент
    newInventory[n - 1] = item;

    // Переносим владение (старый массив автоматически удалится)
    inventory = std::move(newInventory);
}

void Inventory::displayInventory() {
    for (int i = 0; i < n; i++) {
        std::cout << inventory[i] << "\n";
    }
}