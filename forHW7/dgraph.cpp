//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Aaron Johnson
// File Type: dgraph implementation file
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0) initialize countUsed to be 0
{
  for(int i = 0; i < SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }
  countUsed = 0;
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
  // llist was called!
}

void dgraph::fillTable()  // be sure to read from a specified file
{
  string fname; // file name
  char x; // used to add ajacents to list

  cout << "Enter a file name: ";
  cin >> fname;

  ifstream fin(fname.c_str(), ios::in); // declare and open fname
  while(fin >> Gtable[countUsed].vertexName)  // IF I CAN READ THE NAME
    { 
      fin >> Gtable[countUsed].outDegree;
      // Then for the OutDegree times (for-loop):
      for(int i = 0; i < Gtable[countUsed].outDegree; i++)
      {
	fin >> x;
	(Gtable[countUsed].adjacentOnes).addRear(x);   // this is a slist function from HW3
      }      
      countUsed++;
    }

  fin.close(); // close file
}
void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows
  cout << "V " << "Out  Vis" << "  Adj" << endl; // could be made with setw() as well
  cout << "---------------------" << endl;
  for(int i = 0; i < countUsed; i++)
    {
      cout << Gtable[i].vertexName;
      cout << "  " << Gtable[i].outDegree;
      cout << "    ";
      cout << Gtable[i].visit; 
      Gtable[i].adjacentOnes.displayAll();
    }
}

int dgraph::findOutDegree(char V)// throws exception
{
  int location = V - 65; // assigns vertex with slot
  if(Gtable[location].vertexName == V) // checks for name match
    {
      return Gtable[location].outDegree;
    }
  throw BadVertex(); // exception
}

slist dgraph::findAdjacency(char V)// throws exception
{
  int location = V - 65; // assigns vertex with slot
  if(Gtable[location].vertexName == V) // checks for name match
    {
      return Gtable[location].adjacentOnes;
    }
  throw BadVertex(); // exception
}

// marks a visit to vertex
void dgraph::visit(int count, char V)
{
  int location = V - 65; // assigns vertex with slot
  if(Gtable[location].vertexName == V) // checks for name match
    {
      Gtable[location].visit = count;
    }
}

// checks if a vertex is marked
bool dgraph::isMarked(char V)
{
  int location = V - 65; // assigns vertex with slot
  if(Gtable[location].vertexName == V) // checks for name match
    {
      if(Gtable[location].visit > 0)
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
}
