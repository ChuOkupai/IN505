#ifndef CSTRING_H
# define CSTRING_H

class CString
{
	private:
		char		*s;
		int			taille;
		static int	n;
	public:
		// Constructeurs
		CString();
		CString(const char c);
		CString(const char *s);

		// Destructeur
		~CString();

		// Méthodes
		CString		plus(const char c) const;
		char		*getString() const;
		bool		plusGrandQue(CString &s) const;
		bool		infOuEgale(CString &s) const;
		const CString		plusGrand(CString &s) const;
		static int	nbrChaines();
};

#endif
