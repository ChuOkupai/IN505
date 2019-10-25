#include <cstring>
#include <iostream>
#include "Definition.hpp"

Definition::Definition(const char *clef, const char *def)
{
	this->clef = new CString(clef);
	this->def = new CString(def);
}

Definition::~Definition()
{
	delete (clef);
	delete (def);
}

char	*Definition::getClef() const
{
	return (clef->getString());
}

char	*Definition::getDef() const
{
	return (def->getString());
}

