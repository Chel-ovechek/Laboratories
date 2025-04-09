#pragma once
#include <iostream>
#include <string>
#include "Entity.h"

class Player : public Entity {
private:
    int experience; // ��������� ����: ����

public:
    // ����������� ������������ ������
    Player(const std::string& n, int h, int exp)
        : Entity(n, h), experience(exp) {}

    // ��������������� ������ displayInfo
    void displayInfo() const override;
};

