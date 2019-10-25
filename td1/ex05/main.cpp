#include <iostream>
#include "Segment.hpp"

int	main(void)
{
	Segment	*s;
	
	s = new Segment(Point(0, 0), Point(2, 2));
	std::cout << "longueur: " << s->longueur() << '\n';
	std::cout << "estVertical: " << s->estVertical() << '\n';
	std::cout << "estHorizontal: " << s->estHorizontal() << '\n';
	std::cout << "estSurDiagonale: " << s->estSurDiagonale() << '\n';
	delete (s);
	return (0);
}
