#include "Player.h"

void Player::displayInfo() const {
    Entity::displayInfo(); // ����� ������ �������� ������
    std::cout << "Experience: " << experience << std::endl;
}