#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#ifndef HEADER_H
#define HEADER_H

enum Color {
	RED,
	YELLOW,
	GREEN,
	BLUE,
	NOCOLOUR
};

struct House {
	Color color;
	int members;
	bool status;

	House(Color c = Color::RED, int m = 4, bool s = false) {
		color = c;
		members = m;
		status = s;
	}
};

struct Player {
	string name;
	House house[2];
};

void GameConfiguration(Player players[], int numOfPlayers);
void DisplayResults(Player players[], int numOfPlayers);

#endif