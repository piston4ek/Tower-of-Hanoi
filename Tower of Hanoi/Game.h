#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include <vector>
#include "Stack.h"

class Game
{
public:
	Game();
	// Realization of Tower Hanoi solve
	void solve();

	friend std::ostream& operator<<(std::ostream& os, const Game& game);
private:
	std::vector<Stack> m_stacks;
	// For algorytm
	void m_legal_move(unsigned left_pos, unsigned right_pos);
	// For legal move
	void m_move(unsigned left_pos, unsigned right_pos);

	// Solution #2, by using recursion
	void m_move(unsigned start, unsigned end, Stack& source, Stack& target, Stack& spare);
	void m_move(Stack& source, Stack& target);
};

#endif // !GAME_H_
