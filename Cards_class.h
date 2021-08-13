#pragma once
#include <map>
#include <vector>
#include <string>

// Player struct
struct player{
    int score;
    std::string name;
};

// Card struct
struct card{
    std::string answer,question, hint;
};

class Cards
{

    private:
	std::vector<card> Card_map;
    	std::vector<player> players;
	
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
	void addPlayers();
   	void print_map();
    	void leaderboard();
    	void displayWinner();


};
