#include <iostream>

int		main(void)
{
	char	**s;
	int		i;
	int		t[10] = { 1, 4, 9, 0, 3, 8, 7, 6, 5, 2 };
	int		*p;

	p = t;
	for (i = 0; i < 10; i++)
	{
		std::cout << p[i];
		std::cout << ((i < 9) ? ", " : ".\n");
	}
	s = new char*[3];
	s[0] = (char*)"truc";
	s[1] = (char*)"machin";
	s[2] = (char*)"chose";
	for (i = 0; i < 3; i++)
		std::cout << s[i] << '\n';
	delete s;
	return (0);
}
