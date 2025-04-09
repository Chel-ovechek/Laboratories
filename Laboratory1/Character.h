#pragma once
#include <iostream>
#include <string>

class Character
{
private: 
	std::string name;
	int curent_health;
	int max_health;
	int attack;
	int defense;
public:
	Character(const std::string& , int , int, int);
	int  getHealth() const { return curent_health; }
	void displayInfo() const {
		std::cout << "Name: " << name << ", HP: " << curent_health
			<< ", Attack: " << attack << ", Defense: " << defense << std::endl;
	}
	void attackEnemy(Character&);
	void heal(int);
	void takeDamage(int);
};

