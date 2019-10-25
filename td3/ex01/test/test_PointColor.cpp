#include <iostream>
#include "PointColor.hpp"

int	main(void)
{
	PointColor *a, b;
	
	a = new PointColor(3.5, 8.99, bleu);
	std::cout << "a:\n";
	a->afficher();
	delete (a);
	b.cloner(*a);
	std::cout << "b:\n";
	b.afficher();
	return (0);
}
