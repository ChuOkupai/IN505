#include <iostream>
#include "Definition.hpp"

int	main(void)
{
	Definition homer("Homer", "Buveur de biere");

	std::cout << "la definition du mot " << homer.getClef() << " est " <<
	homer.getDef() << std::endl;
	return (0);
} 
