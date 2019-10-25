#ifndef POINT_H
# define POINT_H

class Point
{
	private:
		double x;
		double y;
	public:
		// Constructeurs
		Point();
		Point(double v);
		Point(double x, double y);

		// Destructeur
		~Point();

		// Méthodes
		void			afficher() const;
		void			cloner(const Point &p);
		double			getX() const;
		double			getY() const;
};

#endif
