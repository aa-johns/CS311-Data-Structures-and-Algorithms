// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//-----------------------------------------------------
// NAME: Aaron Johnson

#include <iostream>
#include <string>
using namespace std;

class elem_t
{
 private:
  string name;
  string publisher;
  string platform;
  string releaseDate;

 public:
  elem_t();  // to create a blank elem_t object
  elem_t(string,string,string,string); // to create an initialized elem_t object

  bool operator==(elem_t);  // overload == for search
  bool operator!=(elem_t);  // overload != for search
  // In search == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements?  

  bool operator<(elem_t); // overload< for comparison in binstree
  bool operator>(elem_t); // overload> for comparison in binstree

  // this overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const elem_t&);  
  
  friend class BST;  // client of this class is BST which needs access to the key part of elem_t 

};
