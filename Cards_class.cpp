#include "Cards.h"
#include <iostream>
#include <fstream>
#include <sstream>

template<typename K, typename V>
void print_map(std::map<K, V> const& m)
{
	for (auto const& pair : m) {
		std::cout << "{" << pair.first << ": " << pair.second << "}\n";
	}
}

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
	update_dictionary("Cultural_tags_dictionary.txt");

	//players
}

void Cards::AddCard()
{
	//implement write function


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

void Cards::update_dictionary(std::string inputfile)
{
	std::ifstream indata; // indata is like cin
	int num; // variable for input value
	std::string temp_key;
	std::string temp_value;
	char trash = ',';
	indata.open(inputfile); // opens the file
	std::string text_from_file;
	if (!indata) { // file couldn't be opened
		std::cerr << "Error: file could not be opened" << std::endl;
		exit(1);
	}
	while (getline(indata, text_from_file)) {
		std::stringstream ss(text_from_file);
		getline(ss, temp_key, ',');
		getline(ss, temp_value, ',');
		Card_map[temp_key] = temp_value;
	}

	//debug
	print_map(Card_map);


}