#include "Game.h"

Game::Game()
{
	// Create the 3 empty stacks
	for (int i = 0; i < 3; i++)
	{
		Stack stackOfCubes;
		m_stacks.push_back(stackOfCubes);
	}

	// Creathe the 4 cubes, placing each on the [0]th stack:
	Cube blue(4, uiuc::BLUE);
	m_stacks[0].push_back(blue);

	Cube orange(3, uiuc::ORANGE);
	m_stacks[0].push_back(orange);

	Cube purple(2, uiuc::PURPLE);
	m_stacks[0].push_back(purple);

	Cube yellow(1, uiuc::YELLOW);
	m_stacks[0].push_back(yellow);
}

void Game::solve()
{
	using std::cout;
	using std::cin;
	int choice;
	cout << "Do you want first or second solution of problem?\n[Enter <1> or <2>]: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		while (m_stacks.at(2).size() != 4)
		{
			m_legal_move(0, 1);
			m_legal_move(0, 2);
			m_legal_move(1, 2);
		}
		break;
	case 2:
		m_move(0, 3, m_stacks.at(0), m_stacks.at(2), m_stacks.at(1));
		break;
	default:
		break;
	}
}

void Game::m_legal_move(unsigned left_pos, unsigned right_pos)
{
	// Check if we have empty stack at[right_pos] 
	if (m_stacks.at(right_pos).size() == 0)
	{
		m_move(left_pos, right_pos);
	}

	// Check if we have empty stack at[left_pos]
	else if (m_stacks.at(left_pos).size() == 0)
	{
		m_move(right_pos, left_pos);
	}

	// If cube in the left position has less lenght that one in  right position
	else if (m_stacks.at(left_pos).peekTop().getLenght() < m_stacks.at(right_pos).peekTop().getLenght())
	{
		m_move(left_pos, right_pos);
	}

	// Vice versa
	else
	{
		m_move(right_pos, left_pos);
	}
	//std::cout << *this << std::endl;		// for debug
}

void Game::m_move(unsigned index1, unsigned index2)
{
	Cube temp = m_stacks.at(index1).removeTop();
	m_stacks.at(index2).push_back(temp);
}

void Game::m_move(unsigned start, unsigned end, Stack& source, Stack& target, Stack& spare)
{
	// Check if we are only moving one cube:
	if (start == end)
	{
		// If so, move it directly:
		m_move(source, target);
	}
	else
	{
		// Otherwise, use our move strategy:
		m_move(start + 1, end, source, spare, target);
		m_move(start, start, source, target, spare);
		m_move(start + 1, end, spare, target, source);
	}
}

void Game::m_move(Stack& source, Stack& target)
{
	Cube temp = source.removeTop();
	target.push_back(temp);
}

std::ostream& operator<<(std::ostream& os, const Game& game)
{
	for (int i = 0; i < game.m_stacks.size(); i++)
		os << "Stack[" << i << "]: " << game.m_stacks[i] << std::endl;
	return os;
}
