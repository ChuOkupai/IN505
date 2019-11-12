#ifndef CPILE_H
# define CPILE_H
# include "CList.hpp"

class CPile: public CList
{
public:
	CPile	&operator < (const int contenu);
};

#endif
