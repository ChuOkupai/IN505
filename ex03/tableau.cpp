#include <iostream>

using namespace std;

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
		cout << t[i];
		cout << ((++i < size) ? ", " : ".\n");
	}
}
