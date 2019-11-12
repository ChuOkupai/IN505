#include <cstddef>
#include "CList.hpp"

CList::CList() : tete(NULL) {}

CList::~CList()
{
	t_noeud *n;

	while (tete)
	{
		n = tete->suivant;
		delete tete;
		tete = n;
	}
}

CList	&CList::operator > (int &contenu)
{
	t_noeud *n;

	if (tete)
	{
		contenu = tete->contenu;
		n = tete->suivant;
		delete tete;
		tete = n;
	}
	else
		std::cerr << "erreur: Liste vide" << '\n';
	return *this;
}

std::ostream&	operator << (std::ostream& o, const CList& p)
{
	t_noeud *n;
	
	n = p.tete;
	while (n)
	{
		o << n->contenu;
		o << ((n = n->suivant) ? " -> " : "\n");
	}
	return o;
}
