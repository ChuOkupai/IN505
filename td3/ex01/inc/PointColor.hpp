#ifndef POINTCOLOR_H
# define POINTCOLOR_H

# include "Point.hpp"

enum e_couleur
{
	noir,
	blanc,
	rouge,
	vert,
	bleu
};

class PointColor : public Point
{
	private:
		e_couleur couleur;

	public:
		// Constructeurs
		PointColor();
		PointColor(double v);
		PointColor(double x, double y);
		PointColor(enum e_couleur e);
		PointColor(double v, enum e_couleur e);
		PointColor(double x, double y, enum e_couleur e);

		// Destructeur
		~PointColor();

		// Méthodes
		void		afficher() const;
		void		cloner(const PointColor &p);
		e_couleur	getCouleur() const;
};

#endif
