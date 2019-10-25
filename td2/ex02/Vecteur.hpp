#ifndef VECTEUR_H
# define VECTEUR_H

# include <iostream>

# ifndef TAB_DYNAMIQUE
#  define TAB_DYNAMIQUE 0
# endif

# if TAB_DYNAMIQUE == 0
class Vecteur
{
private:
	int	*vect;
	int	dim;

public:
	// Constructeurs
	Vecteur(int);
	Vecteur(const Vecteur &);

	// Destructeur
	~Vecteur();

	// Méthodes
	Vecteur	&operator = (const Vecteur &);
	int		&operator [] (int) const;
	Vecteur	&operator += (const int);
	friend std::ostream &operator << (std::ostream &, Vecteur &);
	friend std::istream &operator >> (std::istream &, Vecteur &);
};
# else
class Node
{
	friend class Vecteur;
private:
	int		i;
	Node	*next;
public:
	// Constructeur
	Node(int);

	// Destructeur
	~Node();

	// Méthodes
	int		&getInt();
	Node	*getNext();
};

class Vecteur
{
private:
	Node	*head;
	int		length;

public:
	// Constructeurs
	Vecteur(int = 0); // si pas de paramètre, initialise à 0
	Vecteur(const Vecteur &);

	// Destructeur
	~Vecteur();

	// Méthodes
	Vecteur	&operator = (const Vecteur &);
	int		&operator [] (int) const;
	Vecteur	&operator += (const int);
	friend std::ostream &operator << (std::ostream &, Vecteur &);
	friend std::istream &operator >> (std::istream &, Vecteur &);
};
# endif
#endif
