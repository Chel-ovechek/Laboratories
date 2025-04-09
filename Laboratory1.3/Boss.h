#pragma once
#include "Monster.h"
class Boss: public Monster
{
public:
	Boss(const std::string& n, int h, int a, int d)
		: Monster(n, h, a, d) {}

	void toAttack(Entity& target) override;

	// Переопределение метода displayInfo
	void displayInfo() const override;
};

