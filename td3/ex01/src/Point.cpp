#include <iostream>
#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(double v) : x(v), y(v)
{}

Point::Point(double x, double y) : x(x), y(y)
{}

Point::~Point()
{
	std::cout << "Point: appel au destructeur" << '\n';
}

void	Point::afficher() const
{
	std::cout << "x = " << this->x << '\n';
	std::cout << "y = " << this->y << '\n';
}

void	Point::cloner(const Point &p)
{
	this->x = p.getX();
	this->y = p.getY();
}

double	Point::getX() const
{
	return (this->x);
}

double	Point::getY() const
{
	return (this->y);
}
