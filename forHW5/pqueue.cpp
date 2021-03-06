// CS311 Yoshii - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Aaron Johnson
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  
  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue(){}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  // ** add the job j at the rear (and update count)
  // **   if possible else display error message. 
  if(MAX == count)
    {
      cout << "Error: too many elements!" << endl; 
    }
  else
    {
      Q[count] = j;
      count++;
      trickleup(); // moves the job to the right place
    }
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  // ** loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
  for(int i = 0; i <= count-1; i++)
    {
      cout << Q[i] << " ";
    }
  cout << endl;
} 

// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
  // ** swap the values in these locations in Q
  int temp;
  temp = Q[loc1];
  Q[loc1] = Q[loc2];
  Q[loc2] = temp;
}

// Purpose: to make the very last job trickle up to the right location 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  // ** While x is > 0   
  while(x > 0)
    {
      // (*) Call getParent to get the location of the parent
      // based on the child's location.
      int parentloc = getParent(x);
      // compare Q[x] with the parent (*)
      // and if the parent is bigger swap & update x
      // to be the parent . Otherwise stop the loop.      
      if(Q[parentloc] > Q[x])
	{
	  swap(x, parentloc);
	  x = parentloc;
	}
      else
	{
	  break;
	}
    }
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{ 
  // ** return the parent location based on the child loc
  bool childeven = even(childloc);
  if(childeven == true) //if child location is even
    {
      return (childloc-2)/2;
    }
  else //else child location is odd
    {
      return (childloc-1)/2;
    }
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; 
}

// Purpose: to reheapify the Pqueue after printing
//  This trickles down
void pqueue::reheapify()
{ 
  // ** Start X at 0 (the root)
  int X = 0;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--; // update count

  // Find the location of the smaller child

  // while X is within the array: 
  while(X < count - 1)
    {
      int childloc = getSmallerchild(X);
      // (if the location of both children are off the tree, stop the loop).
      if(childloc == -1)
	{
	  break;
	}
      // If the smaller child is smaller than the parent,     
      // swap and X becomes the smaller child's location.
      else if(Q[childloc] < Q[X])
	{
	  swap(X, childloc);
	}
      X++;
    }
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
  int leftchild = 2*i+1;
  int rightchild = 2*i+2;

  // ** return the location of the smaller child 
  //    Be careful because one or both of them may be
  //    beyond count-1.  Check boundaries before you 
  //    compare Q contents!!!!  
  if(leftchild >= count && rightchild >= count)
    {
      return -1;
    }
  else if(rightchild >= count) 
    { 
      return leftchild;
    }
  else if(leftchild >= count)
    {
      return rightchild;
    }
  else if(Q[leftchild] < Q[rightchild])
    {
      return leftchild;
    }
  else  
    {
      return rightchild;
    }
}
