#ifndef DEFINITION_H
# define DEFINITION_H

# include <CString.hpp>

class Definition
{
	private:
		CString	*clef;
		CString	*def;
	public:
		// Constructeurs
		Definition(const char *clef, const char *def);

		// Destructeur
		~Definition();

		// Méthodes
		char	*getClef() const;
		char	*getDef() const;
};

#endif
