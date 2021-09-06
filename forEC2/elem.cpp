// CS311 Yoshii - defines node element level functions for a Node for dgraph2 use
// ------------------------------------------------------------

// ====================================
// EC related element definition
// NAME: **
// File: elem.cpp for graph algorithms
// ====================================

#include "elem.h"

// regular constructor - blank element
el_t::el_t()
{
  **
}

// special constructor - initialize element with name and weight
el_t::el_t(char n, int w)
{
 **
}

// defines == for elements during search
// based on the name part only
bool el_t::operator==(el_t OtherOne)
{
  **
}

// overload cout for el_t 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.name << "+" << E.weight;
  return os;  
}  

