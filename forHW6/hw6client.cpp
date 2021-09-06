// CS311 Yoshii
// HW6 Client file 
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Aaron Johnson
// File type: Client File a.k.a (tester)
// ================================================

#include "dgraph.h"
#include <iostream>
using namespace std;

int main()
{ 
  int user = 1; // while loop condition
  int degree; // returned outDegree
  char x; // user entered vertex
  bool check; // check for exception in display
  slist l1; // to find adjacents

  // 0.Declare table object
  dgraph Table;
  // 1.fillTable()
  Table.fillTable();
  // 2.displayGraph()
  Table.displayGraph();
  cout << endl;
  
  // while (the user does not want to stop)
  while(user == 1)
    {
      check = false;
      // a.the user will specify which vertex     
      cout << "Enter a Vertex: ";
      cin >> x;
      cout << endl;
      // b.findOutDegree of the vertex and display the result
      try
	{
	  degree = Table.findOutDegree(x);
	}
      catch(dgraph::BadVertex)
	{
	  cerr << "ERROR: No vertex " << x << " found!" << endl;
	  check = true;
	}
      if(check == false)
	{
	  cout << "The degree is: " << degree << endl;
	}

      check = false; // reset check

      // b.findAdjacency of the vertex and display the result (see Hint)
      try
	{
	  l1 = Table.findAdjacency(x); 
	}
      catch(dgraph::BadVertex)
	{
	  cerr << "ERROR: No vertex " << x << " found!" << endl;
	  check = true;
	}
      if(check == false)
	{
	  cout << "Adjacents are: ";
	  l1.displayAll();
	  cout << endl;
	}

      // c.catch exception to display error mesg but do not exit
      cout << "Enter one of the following: " << endl;
      cout << "(0) to Quit." << endl;     
      cout << "(1) Look at another Vertex. " << endl;
      cout << "Option: ";
      cin >> user;
    }
}
