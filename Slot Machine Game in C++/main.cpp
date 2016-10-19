/* This code is originally written by me for the example of my tutorials
which you can check on my website. If you ask why am I not using Array, Maps, Class
or another functions in C++, it's because my tutorial hasn't reach that part. But if you
want to change the code using other functions it's better! :)

Enjoy this simple Slot Machine Game

ivanwidyan.com
*/

#pragma once

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int insertCoin = 0;
int Coins = 25;
bool exitGame = false;

int randRange(int, int);
void PlayGame(), MenuGame(), RandomizingSlot(),
PrintingItems(int), Combination(int, int, int);

enum menuLists { Play = 1, Help = 2, Exit = 3 };
enum slotItems { Cherry, Bell, Orange, Bar, Seven };

int main() {
	srand(time(NULL));
	MenuGame();
	if (exitGame) {
		return 0;
	}
}

void MenuGame() {
	int input = 0;
	Coins = 25;
	insertCoin = 0;
	cout << "WELCOME TO 777 SIMPLE SLOT GAME" << endl;
	cout << "		    .-------." << endl;
	cout << "        oO{-  777  -}Oo" << endl;
	cout << "        .=============. __" << endl;
	cout << "        | [a] [X] [o] |(  )" << endl;
	cout << "        | [$] [$] [$] | ||" << endl;
	cout << "        | [X] [o] [$] | ||" << endl;
	cout << "        |             |_||" << endl;
	cout << "        | xxx ::::::: |--'" << endl;
	cout << "        | ooo ::::::: |" << endl;
	cout << "        | $$$ ::::::: |" << endl;
	cout << "        |             |" << endl;
	cout << "        |      __ === |" << endl;
	cout << "        |_____/__\____|" << endl;
	cout << "       /###############\\" << endl;
	cout << "      /#################\\" << endl;
	cout << "     |###################|" << endl;
	cout << "1. PLAY" << endl;
	cout << "2. EXIT" << endl;
	cout << "Type your number: ";
	cin >> input;
	switch (input) {
	case Play:
		cout << endl;
		PlayGame();
		break;
	case Exit:
		exitGame = true;
		break;
	default:
		cout << "Type the correct number" << endl;
		break;
	}
}

void PlayGame() {
	insertCoin = 0;
	while (Coins > 0) {
		cout << "You have " << Coins << " amount of coins" << endl;
		cout << "Insert coin (1 - 3): ";
		cin >> insertCoin;
		if (insertCoin >= 1 && insertCoin <= 3) {
			RandomizingSlot();
			cout << endl;
		}
		else {
			cout << "Type amount of coins between 1 - 3" << endl;
			PlayGame();
		}
	}
	cout << "YOU LOSE! You don't have any coin to play" << endl;
	cout << endl;
	MenuGame();
}

void RandomizingSlot() {
	int firstSlot = randRange(0, 5);
	int secondSlot = randRange(0, 5);
	int thirdSlot = randRange(0, 5);
	firstSlot = 2;
	secondSlot = 2;
	thirdSlot = 2;
	PrintingItems(firstSlot);
	PrintingItems(secondSlot);
	PrintingItems(thirdSlot);
	cout << endl;
	Combination(firstSlot, secondSlot, thirdSlot);
	cout << endl;
}

void PrintingItems(int input) {
	switch (input) {
	case Cherry:
		cout << "Cherry ";
		break;
	case Bell:
		cout << "Bell ";
		break;
	case Orange:
		cout << "Orange ";
		break;
	case Bar:
		cout << "Bar ";
		break;
	case Seven:
		cout << "7 ";
		break;
	default:
		break;
	}
}

void Combination(int firstitems, int seconditems, int thirditems) {
	bool tripleCherry = false;
	if (firstitems == Seven && seconditems == Seven && thirditems == Seven) {
		if (insertCoin == 1) {
			cout << "You Get 100 coin!" << endl;
			Coins += 100;
		}
		else if (insertCoin == 2) {
			cout << "You Get 100 coin!" << endl;
			Coins += 200;
		}
		else if (insertCoin == 3) {
			cout << "JACKPOT! You Get 25000 coin!" << endl;
			Coins += 25000;
		}
	}
	else if ((firstitems == Bar && seconditems == Bell && thirditems == Bell) ||
		(firstitems == Bell && seconditems == Bar && thirditems == Bell) ||
		(firstitems == Bell && seconditems == Bell && thirditems == Bar)) {
		if (firstitems)
			if (insertCoin == 1) {
				cout << "You Get 15 coin!" << endl;
				Coins += 15;
			}
			else if (insertCoin == 2) {
				cout << "You Get 30 coin!" << endl;
				Coins += 30;
			}
			else if (insertCoin == 3) {
				cout << "You Get 45 coin!" << endl;
				Coins += 45;
			}
	}
	else if ((firstitems == Bar && seconditems == Orange && thirditems == Orange) ||
		(firstitems == Orange && seconditems == Bar && thirditems == Orange) ||
		(firstitems == Orange && seconditems == Orange && thirditems == Bar)) {
		if (firstitems)
			if (insertCoin == 1) {
				cout << "You Get 15 coin!" << endl;
				Coins += 15;
			}
			else if (insertCoin == 2) {
				cout << "You Get 30 coin!" << endl;
				Coins += 30;
			}
			else if (insertCoin == 3) {
				cout << "You Get 45 coin!" << endl;
				Coins += 45;
			}
	}
	else if (firstitems == Cherry && seconditems == Cherry && thirditems == Cherry) {
		if (insertCoin == 1) {
			cout << "You Get 10 coin!" << endl;
			Coins += 10;
		}
		else if (insertCoin == 2) {
			cout << "You Get 20 coin!" << endl;
			Coins += 20;
		}
		else if (insertCoin == 3) {
			cout << "You Get 30 coin!" << endl;
			Coins += 30;
		}
		tripleCherry = true;
	}
	else if (firstitems == Bar && seconditems == Bar && thirditems == Bar) {
		if (insertCoin == 1) {
			cout << "You Get 5 coin!" << endl;
			Coins += 5;
		}
		else if (insertCoin == 2) {
			cout << "You Get 10 coin!" << endl;
			Coins += 10;
		}
		else if (insertCoin == 3) {
			cout << "You Get 15 coin!" << endl;
			Coins += 15;
		}
	}
	else if (firstitems == Orange && seconditems == Orange && thirditems == Orange) {
		if (insertCoin == 1) {
			cout << "You Get 5 coin!" << endl;
			Coins += 5;
		}
		else if (insertCoin == 2) {
			cout << "You Get 10 coin!" << endl;
			Coins += 10;
		}
		else if (insertCoin == 3) {
			cout << "You Get 15 coin!" << endl;
			Coins += 15;
		}
	}
	else if (firstitems == Bell && seconditems == Bell && thirditems == Bell) {
		if (insertCoin == 1) {
			cout << "You Get 5 coin!" << endl;
			Coins += 5;
		}
		else if (insertCoin == 2) {
			cout << "You Get 10 coin!" << endl;
			Coins += 10;
		}
		else if (insertCoin == 3) {
			cout << "You Get 15 coin!" << endl;
			Coins += 15;
		}
	}
	else if ((firstitems == Orange || seconditems == Orange || thirditems == Orange) &&
		tripleCherry == false) {
		if (firstitems)
			if (insertCoin == 1) {
				cout << "You Get 2 coin!" << endl;
				Coins += 2;
			}
			else if (insertCoin == 2) {
				cout << "You Get 4 coin!" << endl;
				Coins += 4;
			}
			else if (insertCoin == 3) {
				cout << "You Get 6 coin!" << endl;
				Coins += 6;
			}
	}
	tripleCherry = false;
}

int randRange(int low, int high) {
	return rand() % (high - low) + low;
}