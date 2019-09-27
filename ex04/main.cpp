#include <iostream>
#include "Point.hpp"

using namespace std;

int	main(void)
{
	Point *a;
	Point b;
	
	a = new Point(3.5, 8.99);
	cout << "a:\n";
	a->afficher();
	delete (a);
	b.cloner(*a);
	cout << "b:\n";
	b.afficher();
	return (0);
}
