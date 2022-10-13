// main.cpp -- is using for test our solution to Hanoi Tower problem
#include "Game.h"
#include <iostream>

int main()
{
	using std::cout;
	using std::endl;
	Game game;
	cout << "Start a game:\n";
	cout << game << endl;
	game.solve();
	cout << "\nEnd of game:\n";
	cout << game << endl;
	return 0;
}