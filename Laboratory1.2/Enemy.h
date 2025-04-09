#pragma once

#include <iostream>
#include <string>
#include "Entity.h"
class Enemy : public Entity {
private:
    std::string type; // ��������� ����: ��� �����

public:
    // ����������� ������������ ������
    Enemy(const std::string& n, int h, const std::string& t)
        : Entity(n, h), type(t) {}

    // ��������������� ������ displayInfo
    virtual void displayInfo() const override;
};



