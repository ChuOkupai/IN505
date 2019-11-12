#include <iostream>
#include "CFile.hpp"
#include "CPile.hpp"

int	main()
{
	CPile	pile;
	CFile	file;
	CList	*ptList;
	int		i;
	
	ptList = &file;
	*ptList < 0 < 1; //empiler deux valeurs dans la file
	std::cout << *ptList;
	*ptList > i; //récupérer une valeur de la file dans i
	std::cout << *ptList << "i = " << i << '\n';

	ptList = &pile;
	*ptList < 0 < 1; //empiler deux valeurs dans la pile
	std::cout << *ptList;
	*ptList > i; //récupérer une valeur de la pile dans i
	std::cout << *ptList << "i = " << i << '\n';
}
