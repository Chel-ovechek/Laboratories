#include "Enemy.h"

void Enemy::displayInfo() const {
    Entity::displayInfo(); // ����� ������ �������� ������
    std::cout << "Type: " << type << std::endl;
}