#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "header.h"
#include <string>
using namespace std;

int main () {
	const int NUM_OF_PLAYERS = 4;

	Player players[NUM_OF_PLAYERS];

	int numOfPlayers;

	do{
		cout << "How many people will play this game? ";
		cin >> numOfPlayers;

	}while (numOfPlayers != 2 && numOfPlayers != 4);

	GameConfiguration(players, numOfPlayers);
	DisplayResults(players, numOfPlayers);

	cout << "Reducing 1, 2, 3, 4 members from players 1, 2, 3 and 4 respectively. \n";
	for(int i = 0; i < numOfPlayers; i++) {
		for(int j = 0; j < 2; j++) {
			players[i].house[j].members -= (i + 1);
		}
	}


	system("pause");
	return 0;
}