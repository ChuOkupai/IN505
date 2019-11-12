#include <cstddef>
#include "CPile.hpp"

CPile	&CPile::operator < (const int contenu)
{
	t_noeud *n;
	
	n = new t_noeud;
	n->contenu = contenu;
	n->suivant = tete;
	tete = n;
	return *this;
}
