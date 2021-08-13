#include "Cards_class.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


string UpperCase(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

//Print map
void Cards::print_map()
{
    std::cout << "{" << std::endl;
    for (int i = 0; i < Card_map.size(); i++) {
        std::cout << Card_map[i].question << ":"
                  <<  Card_map[i].answer << ":" 
                  << Card_map[i].hint <<std::endl;
    }
}

Cards::Cards()
{
    // srand(time(NULL));
    update_dictionary("Cultural_tags_dictionary.txt");
	Menu();
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

//Print Instructions
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
	addPlayers();
	// var for points,answer,rounds
	int random;
    int points =3;
    std::string answer;
	bool rounds = true;
	int cardCount = 0;
	//map iterator and game loop
    
	while(rounds){

        for(int i =0; i < players.size(); i++){
        
        // get players card
            std:: cout <<std::endl <<players[i].name << " 's Turn"<< std::endl;
            std:: cout <<"Hint: "<< Card_map[cardCount].hint << std::endl << std::endl;
            
            std::cout <<"\t\t"<< Card_map[cardCount].question << std::endl;
        // Get Answer and points
            while(points > 0)   {
                std::cout << "Enter Answer: ";
                
                std::getline(std::cin, answer);
                answer.erase(remove(answer.begin(), answer.end(), ' '), answer.end());
        //Set answer and points
                std::string check =UpperCase(Card_map[cardCount].answer);
                if(UpperCase(answer) == check){
                    std::cout << "CorrectAnswer!" << std::endl;
                    players[i].score += points;
                    std::cout << "Your Score: "<< players[i].score<< std::endl;
                    break;
                }
                else    {
                    //display Incorrect and attempts left
                    points--;
                    std::cout << "Answer Incorrect,Remaining attempts: "<< points << std::endl <<std::endl;
                }   
                
            }
            // reset points, new question
            std::cout << "Answer: " << Card_map[cardCount].answer << std::endl;
            points=3;
            cardCount++;
	    }
	    leaderboard();
	    std::cout << "Do you want another round(Enter 1 for 'Yes' 0 for 'No'): ";
	    std::cin >> rounds;
	    std::cin.ignore();
    }

    displayWinner();
	//players
}

void Cards::AddCard()
{
	std::string outputfile = "Cultural_tags_dictionary.txt";

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
	results += ", ";
	user_input = "";
	while (user_input == "") {
		std::cout << "Insert a new Hint-> ";
		std::getline(std::cin, user_input);
		while (!verify_input(user_input)) {
			user_input = "";
		}
	}
	results += user_input;
	add_to_dictionary(outputfile, results);
	Menu();
}

void Cards::Menu()
{
	std::string user_input = "";
	std::string Menu = "_______________________________________\n"
	    "\n\tWelcome to Cultural Tags\n"
	    "_______________________________________\n\n"
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
	std::string temp_q;
	std::string temp_a;
	std::string temp_h;
	card c1;
	indata.open(inputfile); // opens the file
	std::string text_from_file;
	if (!indata) { // file couldn't be opened
		std::cerr << "Error: file could not be opened" << std::endl;
		exit(1);
	}
	while (getline(indata, text_from_file)) {
	    
		std::stringstream ss(text_from_file);
		getline(ss, temp_q, ',');
		getline(ss, temp_a, ',');
		getline(ss, temp_h, ',');
		c1.question = temp_a;
		c1.answer = temp_q;
		c1.hint = temp_h;
		Card_map.push_back(c1);
	}

	//debug
	//print_map();


}

void Cards::add_to_dictionary(std::string outputfile, std::string input)
{
	std::ofstream foutput;
	foutput.open(outputfile, std::ios::app);
	foutput << std::endl << input;
	foutput.close();
}



void Cards::leaderboard(){
    std::cout << "__________________________" << std::endl;
    std::cout << "Leaderboard" << std::endl;
    std::cout << "__________________________" << std::endl;

    std::cout << "Name\tScore" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name<< "\t "<< players[i].score<< std::endl;
    }
}

 void Cards::displayWinner(){
    int max= players[0].score;
    std:: string maxString=players[0].name;
    
    for (int i = 1; i < players.size(); i++) {
        if (players[i].score > max){
            max = players[i].score;
            maxString =players[i].name;
        }
        else if(players[i].score == max){
            maxString += " and " + players[i].name;
        }
    }
    std::cout << "\n\nCongraluations, " << maxString << " has won the game" << std::endl;
 }

void Cards::addPlayers()
{
    int playersCount;
    
    std::cout << "How many players: ";
    std::cin >> playersCount;
    player p1;
    p1.score = 0;
    
    for(int i =0; i < playersCount; i++){
        std::cout <<"Enter Player " << (i+1) <<"'s name: ";
        std::cin >> p1.name;
        players.push_back(p1);
    }
    std::cin.ignore();
}
