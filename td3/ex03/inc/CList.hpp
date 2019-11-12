#ifndef CLIST_H
# define CLIST_H
# include <iostream>

typedef struct noeud t_noeud;
struct noeud
{
	int		contenu;
	t_noeud	*suivant;
};

class CList
{
protected:
	t_noeud *tete;
public:
	CList();
	~CList();

	// Ajouter un élément
	virtual CList		&operator < (const int contenu) = 0;

	// Récupérer un élément
	virtual CList		&operator > (int &contenu);

	// Affiche une liste
	friend std::ostream	&operator << (std::ostream &, const CList &);
};

#endif
