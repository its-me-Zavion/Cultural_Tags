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
	std::cout << "-The objective of this game is to guess what the #CultureTag (acronym) stands for." << std::endl;
	std::cout << "\nWhen you select \"2) Play Game\" the game will start as follows:" << std::endl;
	std::cout << "   1. The program will you ask for the number of players. Enter how many players." << std::endl;
    	std::cout << "   2. The program will then prompt you to enter names for each player." << std::endl;
    	std::cout << "   3. The game will start by giving a card to the first player and taking their answer." << std::endl;
    	std::cout << "   4. The player will be rewarded 3 points for a correct answer." << std::endl;
    	std::cout << "   5. For incorrect answers, the player will lose one point and be able to try again." << std::endl;
    	std::cout << "   6. The leaderboard will be shown after answer is confirmed, and the game will move"
              << "\n\ton to the next player and next question." << std::endl;
    	std::cout << "   7. After everyone has had a turn, the game will show the current leader and ask if" 
              << "\n\tthe players want another round." << std::endl;
    	std::cout << "   8. If players decline to play another round, the game will display the leader has won the game.\n" << std::endl;
Menu();
}

void Cards::playGame()
{
	update_dictionary("Cultural_tags_dictionary.txt");

	//players
}

void Cards::AddCard()
{
	std::string outputfile = " Cultural_tags_dictionary.txt";

	std::string user_input = "";
	std::string results = "";

	while (user_input == "") {
		std::cout << "Insert a new Question-> ";
		std::getline(std::cin, user_input);
		while (!verify_input(user_input)) {
			user_input = "";
		}

	}
	results += user_input;
	results += ", ";
	user_input = "";
	while (user_input == "") {
		std::cout << "Insert a new Answer-> ";
		std::getline(std::cin, user_input);
		while (!verify_input(user_input)) {
			user_input = "";
		}
	}
	results += user_input;


	//implement write function
	add_to_dictionary(outputfile, results);
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

void Cards::add_to_dictionary(std::string outputfile, std::string input)
{
	std::ofstream foutput;
	foutput.open(outputfile, std::ios::app);
	foutput << std::endl << input;
	foutput.close();
}

bool Cards::verify_input(std::string input)
{
	std::string user_input = "";
	while (user_input == "") {
		std::cout << "Are you sure this is the correct input: '" << input << "'\n";
		std::cout << "-> ";
		std::getline(std::cin, user_input);

		if (user_input == "yes") {
			return true;
		}
		else if (user_input == "no") {
			return false;
		}
		else {
			std::cout << "specify 'yes' or 'no'\n";
			user_input = "";
		};
	}
}
