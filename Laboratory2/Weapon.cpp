#include "Weapon.h"

Weapon::Weapon(const std::string& t, int d, int w) {
	std::cout << "Weapon " << title << " created!\n";
}

Weapon::~Weapon() {
	std::cout << "Weapon " << title << " destroyed!\n";
}

void Weapon::displayInfo() const {
	std::cout << "Title: " << title << ", Damage: " << damage
		<< ", Weight: " << weight << std::endl;
}