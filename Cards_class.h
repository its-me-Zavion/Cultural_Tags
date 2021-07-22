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
	void update_dictionary(std::string);
	void add_to_dictionary(std::string, std::string);
	bool verify_input(std::string);


private:
	std::map<std::string, std::string> Card_map;


};

