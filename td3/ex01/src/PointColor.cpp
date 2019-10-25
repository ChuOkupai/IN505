#include <iostream>
#include "PointColor.hpp"

PointColor::PointColor() : Point(), couleur(noir)
{}

PointColor::PointColor(double v) : Point(v), couleur(noir)
{}

PointColor::PointColor(double x, double y) : Point(x, y), couleur(noir)
{}

PointColor::PointColor(enum e_couleur e) : Point(), couleur(e)
{}

PointColor::PointColor(double v, enum e_couleur e) : Point(v), couleur(e)
{}

PointColor::PointColor(double x, double y, enum e_couleur e) : Point(x, y), couleur(e)
{}

PointColor::~PointColor()
{
	std::cout << "PointColor: appel au destructeur" << '\n';
}

void	PointColor::afficher() const
{
	this->Point::afficher();
	std::cout << "couleur = " << this->couleur << std::endl;
}

void	PointColor::cloner(const PointColor &p)
{
	this->Point::cloner(p);
	couleur = p.getCouleur();
}

e_couleur	PointColor::getCouleur() const
{

	return (this->couleur);
}
