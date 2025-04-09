#include "Inventory.h"

Inventory::Inventory() {
    n = 0;  // ����� �������������
    inventory = nullptr;
}

void Inventory::addItem(const std::string& item) {
    n += 1;  // ����������� ������

  // ������� ����� ������ � ����� ��������
    std::unique_ptr<std::string[]> newInventory(new std::string[n]);

    // �������� ������ ��������
    for (int i = 0; i < n - 1; i++) {
        newInventory[i] = inventory[i];
    }

    // ��������� ����� �������
    newInventory[n - 1] = item;

    // ��������� �������� (������ ������ ������������� ��������)
    inventory = std::move(newInventory);
}

void Inventory::displayInventory() {
    for (int i = 0; i < n; i++) {
        std::cout << inventory[i] << "\n";
    }
}