//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Aaron Johnson
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================
using namespace std;
#include<iostream>
#include"llist.h" 

// Constructor for linked list. 
llist::llist()
{ 
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

// Destructor for linked list.
llist::~llist()
{ 
  el_t tmp; // holding variable
  
  while(!isEmpty())
    {
      deleteFront(tmp);
    }
}

//PURPOSE: return true if Front and Rear are both pointing to NULL and Count is 0
//PARAMETER: None
bool llist::isEmpty() // be sure to check all 3 data members
{
  if((Front == NULL) && (Rear == NULL) && (Count == 0))
    {
      return true;
    }
  else
    {
      return false;
    }
}

//PURPOSE: display each element of the list starting from Front, enclosed in  [ ] followed by endl
//PARAMETER: None
void llist::displayAll()// be sure to display horizontally in [  ] with blanks between elements
{
  if(isEmpty()) // special case if list is empty
    {
      cout << "[ Empty ]" << endl;
    }
  else // traverse the list and print each node
    {
      Node* nodePtr = Front; // node pointer that will traverse the list 
      cout << "[ ";
      while(nodePtr != NULL)
	{
	  cout << nodePtr->Elem << " ";
	  nodePtr = nodePtr->Next;
	}
      cout << "]" << endl;
    }
}
  
//PURPOSE: add new node to the rear of the list and assign it a value
//PARAMETER: NewNum is the value that will be assigned to the new node.
void llist::addRear(el_t NewNum)  // comment the 2 cases
{ 
  // special case: if this is going to be the very first node, you must create a new node and make Front and Rear point to it. Put NewNum in the Elem field of this new node. Count is updated.
  if(Front == NULL)
    {
      Front = new Node; // new node that will be added to rear
      Rear = Front;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;
    }

  // regular case:  add a new node at the rear and puts NewNum in the Elem field of this new node. Count is updated.
  else
    {
      Rear->Next = new Node; // new node that will be added to rear
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;
    }
}

//PURPOSE: add node to the front of the list and assign it a value
//PARAMETER: NewNum is the value that will be assigned to the new node.
void llist::addFront(el_t NewNum)  // comment the 2 cases
{ 
  // special case: if this is going to be the very first node, you must create a new node and make Front and Rear point to it. Put NewNum in the Elem field of this new node. Count is updated.
  if(Front == NULL)
    {
      Front = new Node; // new node that will be added to Front
      Front->Elem = NewNum;
      Front->Next = NULL;
      Rear = Front;
      Count++;
    }
  
  // regular case:  add a new node at the front and puts NewNum in the Elem field of this new node. Count is updated
  else
    {
      Node* newNode = new Node; // new node that will be added to front
      newNode->Elem = NewNum; 
      newNode->Next = Front;
      Front = newNode;
      Count++;
    }
}

//PURPOSE: delete the node at the front of the list
//PARAMETER: OldNum is a variable holding the deleted node's value
void llist::deleteFront(el_t& OldNum) // comment the 3 cases 
{ 
  // error case: if the List is empty, throw an exception
  if(isEmpty())
    {
      throw Underflow();
    }
  
  // special case: if this is going to make the list empty, give back the front node element through OldNum (pass by reference) and also remove the front node. Count is updated. Make sure both Front and Rear both become NULL.
  else if(Count == 1)
    {
      OldNum = Front->Elem;
      delete Front;
      Front = NULL;
      Rear = NULL;
      Count--;    
    }
  
  // regular case:  give back the front node element through OldNum (pass by reference) and also remove the front node. Count is updated
  else
    {
      OldNum = Front->Elem;
      Node* Second;
      Second = Front->Next; // second points to second element
      delete Front;
      Front = Second;
      Count--;
    }
}

//PURPOSE: delete the node at the rear of the list
//PARAMETER: OldNum is a variable holding the deleted node's value 
void llist::deleteRear(el_t& OldNum) // comment the 3 cases
{
  // error case: if empty, throw an exception.
  if(isEmpty())
    {
      throw Underflow();
    }
  
  // special case: if this is going to make the list empty, give back the rear node element through OldNum (pass by reference) and also remove the rear node. Count is updated. Make sure both Front and Rear become NULL).
  else if(Count == 1)
    {
      OldNum = Rear->Elem;
      delete Rear;
      Front = NULL;
      Rear = NULL;
      Count--;
    }

  // regular case: give back the rear node element through OldNum (pass by reference) and also remove the rear node. Count is updated.
  else
    {
      Node* nodePtr = Front; // nodeptr is used to traverse the list

      while(nodePtr->Next != Rear) //Stop before rear
	{
	  nodePtr = nodePtr->Next;
	}      
     
      OldNum = Rear->Elem;
      delete Rear; //Delete rear
      Rear = nodePtr; //point rear to nodePtr
      Rear->Next = NULL;
      Count--;
    }
}

/* harder ones follow */

// Utility Function to move a local pointer to the Ith node
//PARAMETER: I is the user specified index in the list. temp is a local pointer
void llist::moveTo(int I, Node*& temp)
{ 
  // moves temp I-1 times(to Ith node)
  for(int j = 1; j <= I-1; j++) 
    {
      temp = temp->Next;
    }
}

//PURPOSE: delete the node at the specified position
//PARAMETER: I is the variable that holds the user specified index in list. OldNum is a variable holding the deleted node's value.
void llist::deleteIth(int I, el_t& OldNum)  // use moveTo to move local pointers. Be sure to comment to which node you are moving them.
{ 
  // Error cases: If I is an illegal value (i.e. > Count or < 1) throw an exception.
  if(I > Count || I < 1)
    {
      throw OutOfRange();
    }
  // special case: if (I == 1), call deleteFront
  else if(I == 1)
    {
      deleteFront(OldNum);
    }
  // special case: if (I == count), call deleteRear
  else if(I == Count)
    {
      deleteRear(OldNum);
    }
  // Regular case: will delete the Ith node (I starts out at 1). Count is updated.
  else
    {
      Node* nodePtr = Front; // local pointer to traverse list              
      Node* p = Front; // local pointer to traverse list                    

      moveTo(I-1,nodePtr); // moves nodeptr to i-1th node                   
      moveTo(I+1,p); // moves p to i+1th node  

      OldNum = nodePtr->Next->Elem; // save oldnum to be deleted            
      delete nodePtr->Next; // delete i                                     
      nodePtr->Next = p; // point i-1th node to i+1th node                  
      Count--; // update count
    }
}

//PURPOSE: add a node to the specified location in the list
//PARAMETER: I is the variable that holds the user specified index in the list. newNum is a value that will be assigned to the new node.
void llist::insertIth(int I, el_t newNum) // use moveTo to move local pointers. Be sure to comment to which node you are moving them. 
{ 
  // Error cases: If I is an illegal value (i.e. > Count or < 1) throw an exception.
  if(I > Count+1 || I < 1)
    {
      throw OutOfRange();
    }

  // special case: if (I == 1), call addFront                  
  else if(I == 1)
    {
      addFront(newNum);
    }

  // special case: if (I == count), call addRear    
  else if(I == Count+1)
    {
      addRear(newNum);
    }

  // Regular case: will insert the Ith node (I starts out at 1). Count is updated.
  else 
    {
      Node* nodePtr = Front; // local pointer to traverse list
      
      moveTo(I-1,nodePtr); // move nodePtr to i-1th node
      
      Node* p = nodePtr->Next; // local pointer temp points to ith node.
      nodePtr->Next = new Node; // create new node and let i-1th->next point to it
      nodePtr->Next->Next = p; // make new node->next point to ith node.
      nodePtr->Next->Elem = newNum; // give new node its value
      Count++; // update count
    }
}
 
//PURPOSE: Copy constructor for pass by value and return by value
//PARAMETER: Original is the original list that is being copied from  
llist::llist(const llist& Original) // use my code
{ 
  Front = NULL; Rear = NULL; Count = 0;
  Node* P; // local pointer for Original
  P = Original.Front;

  while (P != NULL)  // a loop which repeats until you reach the end of Original. 
    {
      this->addRear(P->Elem);    //P’s element is added to this->
      P = P->Next;                         // Go to the next node in Original   
    } 

  //  Nothing to return because this is a constructor.
}

//PURPOSE: allows client to use = operator for linked list objects
//PARAMETER: OtherOne is the list that is being assigned to "this"
llist& llist::operator=(const llist& OtherOne) // use my code
{ 
  el_t x;
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (!this->isEmpty())
	this->deleteRear(x);  
      // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P; // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem); //P’s element is added to this->
	  P = P->Next; // Go to the next node in OtherOne   
	} 
    } // end of if              
  return *this; // return the result unconditionally. Note that the result is returned by reference.
}
