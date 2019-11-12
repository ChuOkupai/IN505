#include <cstddef>
#include "CFile.hpp"

CFile	&CFile::operator < (const int contenu)
{
	t_noeud *dernier;
	t_noeud *n;
	
	n = new t_noeud;
	n->contenu = contenu;
	n->suivant = NULL;
	if ((dernier = tete))
	{
		while (dernier->suivant)
			dernier = dernier->suivant;
		dernier->suivant = n;
	}
	else
		tete = n;
	return *this;
}
