#ifndef SEGMENT_H
# define SEGMENT_H

# include <Point.hpp>

class Segment
{
	private:
		Point a;
		Point b;
	public:
		// Constructeurs
		Segment();
		Segment(const Point &p);
		Segment(const Point &a, const Point &b);

		// Destructeur
		~Segment();

		// Méthodes
		double	longueur() const;
		bool	estVertical() const;
		bool	estHorizontal() const;
		bool	estSurDiagonale() const;
};

#endif
