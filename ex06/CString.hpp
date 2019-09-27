#ifndef CSTRING_H
# define CSTRING_H

class CString
{
	private:
		char *s;
	public:
		// Constructeurs
		CString();
		CString(const char c);
		CString(const char &*s);

		// Destructeur
		~Segment();

		// Méthodes
		char	*getString() const;
		bool	plusGrandQue() const;
		bool	infOuEgale() const;
		CString	plusGrand() const;
		int		nbrChaines() const;
};

#endif
