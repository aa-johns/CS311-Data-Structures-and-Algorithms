//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Aaron Johnson
// Compiler:  g++ 
// File type: header file  llist.h
//=======================================================

// alias el_t : element type definition
typedef char el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};

//---------------------------------------------------------

class llist
{
 protected: //UPDATED HW3P2*
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
  // utility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:
  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range
  
  llist();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // return true if Front and Rear are both pointing to NULL and Count is 0
  bool isEmpty();
    
  // display each element of the list starting from Front, enclosed in [ ] followed by endl
  void displayAll();

  // add a new node to the front of the list
  void addFront(el_t);
    
  // add a new node to the rear of the list
  void addRear(el_t);

  // delete the front node 
  void deleteFront(el_t&);
    
  // delete the rear node
  void deleteRear(el_t&);
    
  // deletes the user specified node 
  void deleteIth(int, el_t&);  // calls moveTo

  // add an element to the user specified location
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 
};
