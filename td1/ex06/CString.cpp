#include <cstring>
#include "CString.hpp"

int CString::n = 0;

CString::CString()
{
	s = new char[1];
	s[0] = '\0';
	taille = 0;
	n++;
}

CString::CString(const char c)
{
	s = new char[2];
	s[0] = c;
	s[1] = '\0';
	taille = 1;
	n++;
}

CString::CString(const char *s)
{
	taille = strlen(s);
	this->s = new char[taille + 1];
	strcpy(this->s, s);
	n++;
}

CString::~CString()
{
	delete (s);
	n--;
}

char	*CString::getString() const
{
	return (s);
}

CString	CString::plus(const char c) const
{
	char	t[taille + 2];

	memcpy(t, s, taille);
	t[taille] = c;
	t[taille + 1] = '\0';
	return (CString(t));
}

bool	CString::plusGrandQue(CString &s) const
{
	return (strcmp(this->s, s.getString()) > 0);
}

bool	CString::infOuEgale(CString &s) const
{
	return (strcmp(this->s, s.getString()) <= 0);
}

const CString	CString::plusGrand(CString &s) const
{
	return ((strcmp(this->s, s.getString()) > 0) ? CString(this->s) : CString(s));
}

int		CString::nbrChaines()
{
	return (n);
}
