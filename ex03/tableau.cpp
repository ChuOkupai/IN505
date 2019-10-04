#include <iostream>

void	tableauEcriture(int *t, int size)
{
	while (size--)
		t[size] = size;
}

void	tableauLecture(const int *t, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		std::cout << t[i];
		std::cout << ((++i < size) ? ", " : ".\n");
	}
}
