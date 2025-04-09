#pragma once
#include <string>
#include <iostream>
#include <memory>
class Inventory
{
private:
	std::string item;
	std::unique_ptr<std::string[]> inventory;
	int n;
public:
	Inventory();
	void addItem(const std::string& item);

	void displayInventory();
};

