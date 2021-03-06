//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Aaron Johnson
// File type: client hw7client.cpp 
//==========================================

#include "dgraph.h"
#include "stack.h"
#include <iostream>
using namespace std;

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{  
  dgraph table;
  stack s1;
  slist l1;
  char V = 'A';
  char vTmp;
  int vCount = 0;
  
  // Display the graph before DFS begins.
  table.fillTable();
  table.displayGraph();

  // Push A onto the stack to start.
  s1.push(V);
 
  // While the stack is not empty do:
  while(!s1.isEmpty())
    {
      // Remove a vertex v from the stack.
      s1.pop(V);
      
      // Display the vertex name.  E.G. “Removed B from stack”
      cout << "Removed " << V << " from stack" << endl;
      
      // If v is not marked yet (visit number is 0) then 
      if(!table.isMarked(V))
	{
	  // mark it (visit it **) and inform the user E.G. “Visit B as 2”
	  table.visit(++vCount, V);
	  cout << "Visit " << V << " as " << vCount << endl;
	  
	  // get its adjacency list
	  l1 = table.findAdjacency(V);

	  // if no adjacent ones inform the user E.G. “Deadend reached – backup”
	  if(l1.isEmpty())
	    {
	      cout << "Deadend reached - backup" << endl;
	    }
	  // else put adjacent ones on the stack (delete from the rear and push) informing the user
	  else
	    {
	      cout << "...pushing ";
              l1.displayAll();
	      
	      while(!l1.isEmpty())
		{
		  l1.deleteRear(vTmp);
		  s1.push(vTmp);
		}
	    }
	}
      // else inform the user E.G. “B had been visited already - backup.”
      else
	{
	  cout << V << " had been visited already - backup." << endl;
	}
      // Display the stack clearly labeling it as the current stack
      s1.displayAll();
    }
  // Display the Graph nicely with visit numbers for all vertices.
  table.displayGraph();

}
