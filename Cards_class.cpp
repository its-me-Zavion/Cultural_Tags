#include "Cards.h"
#include <iostream>
Cards::Cards()
{
	Menu();
}

void Cards::instructions()
{
	Menu();
}

void Cards::playGame()
{
}

void Cards::AddCard()
{
	Menu();
}

void Cards::Menu()
{
	std::string user_input = "";
	std::string Menu = "\n\t\t\tWelcome to Cultural_tags\n"
		"Please Select an option:\n"
		"\tOption 1-> Instructions\n"
		"\tOption 2-> Play Game\n"
		"\tOption 3-> Add New Cards\n";
	std::string User_prompt = "Enter-> ";

	std::cout << Menu;
	std::cout << User_prompt;
	std::getline(std::cin, user_input);

	//get correct input
	while (user_input != "1" && user_input != "2" && user_input != "3") {

		std::cout << "\tPlease select a correct input!\n" + User_prompt;
		std::getline(std::cin, user_input);
	}
	//select which function to call
	char selection;
	selection = user_input[0];

	switch (selection) {
	case '1':
		instructions();
		break;
	case '2':
		playGame();
		break;
	case '3':
		AddCard();
		break;
	}
}
