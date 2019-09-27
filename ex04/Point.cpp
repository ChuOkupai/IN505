#include <iostream>
#include "Point.hpp"

using namespace std;

Point::Point() : x(0), y(0)
{}

Point::Point(double v) : x(v), y(v)
{}

Point::Point(double x, double y) : x(x), y(y)
{}

Point::~Point()
{
	cout << "Point: appel au destructeur" << endl;
}

void	Point::afficher() const
{
	cout << "x = " << this->x << endl;
	cout << "y = " << this->y << endl;
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
