#include <cmath>
#include <iostream>
#include "Segment.hpp"

using namespace std;

Segment::Segment() : a(), b()
{}

Segment::Segment(const Point &p)
{
	this->a.cloner(p);
	this->b.cloner(p);
}

Segment::Segment(const Point &a, const Point &b)
{
	this->a.cloner(a);
	this->b.cloner(b);
}

Segment::~Segment()
{
	cout << "Segment: appel au destructeur" << endl;
}

double	Segment::longueur() const
{
	double dx;
	double dy;

	dx = this->b.getX() - this->a.getX();
	dy = this->b.getY() - this->a.getY();
	return (sqrt(dx * dx + dy * dy));
}

bool	Segment::estVertical() const
{
	return (this->a.getX() == this->b.getX());
}

bool	Segment::estHorizontal() const
{
	return (this->a.getY() == this->b.getY());
}

bool	Segment::estSurDiagonale() const
{
	double dx;
	double dy;

	dx = this->b.getX() - this->a.getX();
	dy = this->b.getY() - this->a.getY();
	return (dx == dy);
}
