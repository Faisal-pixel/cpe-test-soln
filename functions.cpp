#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "header.h"
using namespace std;

void GameConfiguration(Player players[], int numberOfPlayers) {
	string color_string;
	bool exists;
	Color chosen_color = Color::NOCOLOUR;
	bool assigned_houses[4] = {false, false, false, false};
	cout << "Start game configurations... \n";

	for(int i = 0; i < numberOfPlayers; i++) {
		cout << "Enter name for Player " << i + 1 << ": ";
		cin >> players[i].name;

		for(int j = 0; j < (numberOfPlayers == 4 ? 1 : 2); j++) {
			do {
				cout << "\n Choose a color (Red, Yellow, Green, Blue) for " << players[i].name << ": ";
				cin >> color_string;

				if(color_string == "Red" || color_string == "red") {
					chosen_color = Color::RED;
					exists = true;
				} else if(color_string == "Yellow" || color_string == "yellow") {
					chosen_color = Color::YELLOW;
					exists = true;
				} else if(color_string == "Green" || color_string == "green") {
					chosen_color = Color::GREEN;
					exists = true;
				} else if(color_string == "Blue" || color_string == "blue") {
					chosen_color = Color::BLUE;
					exists = true;
				} else {
					cout << "Invalid color, pick from (Red, Yellow, Green, Blue)";
				}

				if(chosen_color != NOCOLOUR) {
					if (assigned_houses[(int)chosen_color]) {
						exists = false;
						cout << "House has already been picked! Choose a different color.\n";
					}
				}

				players[i].house[j] = House(chosen_color, 4, true);
				assigned_houses[(int)chosen_color] = true;
			} while(!exists);
		}
	}
}

void DisplayResults(Player players[], int numberOfPlayers) {
	string HouseNames[4] = {"Red", "Yellow", "Green", "Blue"};
	cout << "\n Results: \n";
	cout << "------------------------------------------------------------- \n";
	cout << "| " << setw(20) << "Name|" <<
		setw(20) << "House|" <<
		setw(20) << "Members|\n";
	cout << "------------------------------------------------------------- \n";

	for(int i = 0; i < numberOfPlayers; i++) {
		
		for(int j = 0; j < 2; j++) {
			if(players[i].house[j].status) {
				cout << "|" <<
					setw(20) << players[i].name << "|" <<
					setw(20) << HouseNames[players[i].house[j].color] << "|" <<
					setw(20) << players[i].house[j].members << "|\n";
			}
		}
	}

	cout << "------------------------------------------------------------- \n";
};