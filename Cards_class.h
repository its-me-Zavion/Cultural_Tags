#pragma once
#include <map>
#include <string>
class Cards
{

public:
	//construcor/menu
	Cards();
	void instructions();
	void playGame();
	void AddCard();
	void Menu();
	

private:
	std::map<std::string, std::string> Card_map;


};

