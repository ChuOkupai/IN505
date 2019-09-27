#include <iostream>
#include "Segment.hpp"

using namespace std;

int	main(void)
{
	Segment	*s;
	
	s = new Segment(Point(0, 0), Point(2, 2));
	cout << "longueur: " << s->longueur() << endl;
	cout << "estVertical: " << s->estVertical() << endl;
	cout << "estHorizontal: " << s->estHorizontal() << endl;
	cout << "estSurDiagonale: " << s->estSurDiagonale() << endl;
	delete (s);
	return (0);
}
