#include <iostream>
#include "CString.hpp"

int	main(void)
{
	CString s1("toto"), s2('q'), s3;
	
	std::cout << "nbrChaines" << CString::nbrChaines() << std::endl;
	//afficher le nombre de chaines créées
	s3 = s1.plus('w');
	std::cout << "s3=" << s3.getString() << std::endl;
	if (s1.plusGrandQue(s2)) // si s1 > s2 au sens alphabétique
		std::cout << "plus grand" << std::endl;
	if (s1.infOuEgale(s2)) // si s1 <= s2 au sens alphabétique
		std::cout << "plus petit" << std::endl;
	s3 = s1.plusGrand(s2); // retourner s1 si s1>s2, s2 sinon
	return (0);
} 
