// Stack.h -- definition of adt - Stack what work with Cubes
#ifndef STACK_H_
#define STACK_H_
#include "/Education/Object-Oriented Data Structures in C++/Cube/Cube/Cube.h"
#include <iostream>
#include <vector>
using namespace uiuc;

class Stack
{
public:
	void push_back(const Cube& cube) { m_cubes.push_back(cube); }
	Cube removeTop();
	Cube& peekTop() {return m_cubes.at(size_t(size() - 1));	}
	unsigned size() const { return m_cubes.size(); }

	friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

private:
	std::vector<Cube> m_cubes;
};

#endif // !STACK_H_