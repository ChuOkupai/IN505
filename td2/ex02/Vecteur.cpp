#include <cstring>
#include "Vecteur.hpp"

#if TAB_DYNAMIQUE == 0
Vecteur::Vecteur(int d)
{
	dim = (d < 1) ? 1 : d;
	vect = new int[dim];
	std::memset(vect, 0, dim * sizeof(int));
}

Vecteur::Vecteur(const Vecteur &v)
{
	dim = v.dim;
	vect = new int[dim];
	std::memcpy(vect, v.vect, dim * sizeof(int));
}

Vecteur::~Vecteur()
{
	std::cout << "Vecteur: appel au destructeur" << '\n';
	delete[] vect;
	dim = 0;
	vect = NULL;
}

Vecteur	&Vecteur::operator = (const Vecteur &v)
{
	if (this == &v)
		return (*this);
	dim = (v.dim < 1) ? 1 : v.dim;
	if (vect)
		delete[] vect;
	vect = new int[dim];
	if (v.dim < 1)
		vect[0] = 0;
	else
		std::memcpy(vect, v.vect, dim * sizeof(int));
	return (*this);
}

int		&Vecteur::operator [] (int i) const
{
	if (i >= 0 && i < dim)
		return (vect[i]);
	std::cerr << "index out of bounds";
	return (vect[0]);
}

Vecteur	&Vecteur::operator += (const int i)
{
	int *t;

	t = new int[dim + 1];
	std::memcpy(t, vect, dim * sizeof(int));
	t[dim++] = i;
	if (vect)
		delete[] vect;
	vect = t;
	return (*this);
}

std::ostream	&operator << (std::ostream &o, Vecteur &v)
{
	int i;

	std::cout << "(";
	i = 0;
	while (i < v.dim)
	{
		std::cout << v[i];
		if (++i < v.dim)
			std::cout << ", ";
	}
	std::cout << ")\n";
	return (o);
}

std::istream	&operator >> (std::istream &i, Vecteur &v)
{
	int j;

	std::cout << "dim: " << v.dim << std::endl;
	j = 0;
	while (j < v.dim)
		i >> v[j++];
	return (i);
}
#else
Node::Node(int i)
{
	this->i = i;
	this->next = NULL;
}

Node::~Node()
{
	if (next)
		delete (next);
}

int		&Node::getInt()
{
	return (i);
}

Node	*Node::getNext()
{
	return (next);
}

Vecteur::Vecteur(int d)
{
	if (d < 1)
	{
		std::cerr << "Vecteur nul" << std::endl;
		d = 1;
	}
	for (int i = 0; i < d; i++)
		(*this) += 0;
}

Vecteur::Vecteur(const Vecteur &v)
{
	if (!v.head)
	{
		head = NULL;
		length = 0;
		return ;
	}
	Node *n = new Node(v.head->i);
	Node *next = v.head->next;

	head = n;
	while (next)
	{
		n->next = new Node(next->i);
		n = n->next;
		next = next->next;
	}
	length = v.length;
}

Vecteur::~Vecteur()
{
	std::cout << "Vecteur: appel au destructeur" << '\n';
	delete (head);
	head = NULL;
	length = 0;
}

Vecteur	&Vecteur::operator = (const Vecteur &v)
{
	if (this == &v)
		return (*this);
	if (head)
		delete (head);
	Node *n = v.head;
	length = v.length;
	head = NULL;
	for (int i = 0; i < length; i++)
	{
		(*this) += n->i;
		n = n->next;
	}
	return (*this);
}

int		&Vecteur::operator [] (int i) const
{
	Node *n = head;

	while (n && i)
	{
		n = n->next;
		i--;
	}
	if (i)
		std::cerr << "index out of bounds";
	return (n->getInt());
}

Vecteur	&Vecteur::operator += (const int i)
{
	Node *n = new Node(i);

	if (head)
	{
		Node *t = head;
		while (t->next)
			t = t->next;
		t->next = n;
	}
	else
		head = n;
	length++;
	return (*this);
}

std::ostream	&operator << (std::ostream &o, Vecteur &v)
{
	Node *n = v.head;

	std::cout << "(";
	while (n)
	{
		std::cout << n->getInt();
		if ((n->getNext()))
			std::cout << ", ";
	}
	std::cout << ")\n";
	return (o);
}

std::istream	&operator >> (std::istream &i, Vecteur &v)
{
	int j;

	std::cout << "dim: " << v.length << std::endl;
	j = 0;
	while (j < v.length)
		i >> v[j++];
	return (i);
}
#endif
