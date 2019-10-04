#include <iostream>
#include "CString.hpp"

CString::CString()
{
	this->s = new char[1];
	this->s[0] = '\0';
}

CString::CString(char c)
{
	this->s = new char[2];
	this->s[0] = c;
	this->s[1] = '\0';
}

CString::CString(double x, double y) : x(x), y(y)
{}
