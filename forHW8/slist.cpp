// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Aaron Johnson
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================
using namespace std;
#include <iostream>
#include "slist.h" 

// Make sure llist constructor and destructors have couts in them

// do not change this one
slist::slist()
{}

// positions always start at 1
int slist::search(el_t key)
{
  Node* nodePtr = Front; // create node to traverse list 
  int nodeCount = 1; // create node counter to return found position 

  while(nodePtr != NULL) // loop until end
    {
      if(nodePtr->Elem == key) // if node matches key
	{
	  return nodeCount; // return its position
	}
      nodePtr = nodePtr->Next; // else move to next pointer
      nodeCount++; // increment position
    }

  return 0; // if not found, return 0
}

el_t slist::search2(el_t key)
{
  Node* nodePtr = Front; // create node to traverse list
 
  while(nodePtr != NULL) // loop until end 
    {
      if(nodePtr->Elem == key) // if node matches elem
        {
          return key; // return whole element
        }
      nodePtr = nodePtr->Next; // else move to next pointer
    }
  
  el_t blank;
  return blank; // if not found, return blank element
}

// don't forget to throw OutOfRange for bad pos 
void slist::replace(el_t element, int pos)
{
  if(pos < 1 || pos > Count) // check for bad pos
    {
      throw OutOfRange();
    }

  Node* nodePtr = Front; // node pointer that will traverse list
  moveTo(pos,nodePtr);
  nodePtr->Elem = element; // replace elem at pos
}

bool slist::operator==(const slist& OtherOne)
{
  if(Count != OtherOne.Count) // initial check if both lists have same count
    {
      return false;
    }

  // create two pointers for both lists
  Node* pointer1 = Front;
  Node* pointer2 = OtherOne.Front;
                                   
  while(pointer1 != NULL) // loop until end of pointer1
    { 
      // if nodes do not match, return false
      if(pointer1->Elem != pointer2->Elem)
        {
          return false;
        }
      // if nodes match, move to next node
      pointer1 = pointer1->Next;
      pointer2 = pointer2->Next;
    }
  // loop is complete, both lists match, return true
  return true;
}
