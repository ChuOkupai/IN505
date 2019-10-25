#include <iostream>
#include "Point.hpp"

int	main(void)
{
	Point *a, b;
	
	a = new Point(3.5, 8.99);
	std::cout << "a:\n";
	a->afficher();
	delete (a);
	b.cloner(*a);
	std::cout << "b:\n";
	b.afficher();
	return (0);
}
