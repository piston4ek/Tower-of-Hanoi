// Cube.h -- definition of Cube class
#ifndef CUBE_H_
#define CUBE_H_
#include <iostream>

namespace uiuc
{ 
	enum HSLAPixel {BLUE, PURPLE, YELLOW, ORANGE};
	class Cube
	{
	public:
		// Default constructor
		Cube(double lenght, HSLAPixel color);		
		// Copy constructor
		Cube(const Cube& obj);			
		// Destructor
		~Cube();
		// Assignment operator
		Cube& operator=(const Cube& obj);
		double getLenght() const { return m_lenght; }
		double getVolume() const { return m_lenght * m_lenght * m_lenght; }
		double getSurfaceArea() const { return 6 * m_lenght * m_lenght; }
		void setLenght(double lenght) { m_lenght = lenght; }

		friend std::ostream& operator<<(std::ostream& os, const Cube& cube);
		// Our cube has colour and lenght
	private:
		double m_lenght;
		HSLAPixel m_color;
	};
}
#endif // !CUBE_H_