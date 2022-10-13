#include "Stack.h"

Cube Stack::removeTop()
{
	Cube temp(m_cubes.at(size() - 1));
	m_cubes.pop_back();
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Stack& stack)
{
	for (int i = 0; i < stack.size(); i++)
		os << stack.m_cubes.at(i) << "\t";
	return os;
}
