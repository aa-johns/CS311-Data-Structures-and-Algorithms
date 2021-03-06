// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------
// NAME: Aaron Johnson
#include "elem.h"

// blank element
elem_t::elem_t()
{
  name = "";
  publisher = "";
  platform = "";
  releaseDate = "";
}

// initializing constructor to create an el_t object 
elem_t::elem_t(string aname,string apublisher, string aplatform, string areleasedate)
{
  name = aname;
  publisher = apublisher;
  platform = aplatform;
  releaseDate = areleasedate;
}
  
// overload == for search based on the name part only
bool elem_t::operator==(elem_t OtherOne)
{
  if (name == OtherOne.name) return true; else return false;
}

// overload != for search based on the name part only
bool elem_t::operator!=(elem_t OtherOne)
{
  if (name != OtherOne.name) return true; else return false;
}

// ***NEW*** overloaded operator< and operator> functions for binstree
bool elem_t::operator<(elem_t OtherOne)
{
  if (name < OtherOne.name) return true; else return false;
}

bool elem_t::operator>(elem_t OtherOne)
{
  if (name > OtherOne.name) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const elem_t& E)  
{  
  os << "Title: " << E.name << endl;
  os << "Publisher: " << E.publisher << endl;
  os << "Platform: " << E.platform << endl;
  os << "Release Date: " << E.releaseDate << endl;
  os << endl;
  return os;  
}  
