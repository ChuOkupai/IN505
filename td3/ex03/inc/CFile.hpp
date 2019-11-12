#ifndef CFILE_H
# define CFILE_H
# include "CList.hpp"

class CFile: public CList
{
public:
	CFile	&operator < (const int contenu);
};

#endif
