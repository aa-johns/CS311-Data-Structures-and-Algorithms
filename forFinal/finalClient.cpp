// NAME: Aaron Johnson   
// File type: client file
#include <iostream>
#include <fstream>
#include <string>
#include "binstree.h"
using namespace std;

int main()
{
  // variables for file input
  string fileName, gName, gPublisher, gPlatform, rDate;
  // variables for display prompt
  string searchKey;
  int count = 0;
  // tree object
  BST tree;
  
  cout << "\nWelcome to the Game Search!\n" << endl;
  cout << "Enter a file name: ";
  cin >> fileName;

  // open file, extract content, close file
  ifstream fin(fileName.c_str(), ios::in); // declare and open fname
  while(fin >> gName)
    {
      fin >> gPublisher >> gPlatform >> rDate;
      elem_t dummy(gName,gPublisher,gPlatform,rDate);
      tree.InsertVertex(dummy);
      count++; // increment game count
    }
  fin.close(); // close file 
  
  cout << "Number of games currently available at our store: " << count << endl << endl;

  // display function used to test if objects were added
  // tree.Display();

  cout << "Enter a Game title that you wish to search for!" << endl;
  cout << "(Ex: SuperMarioBros, CallOfDuty, Minecraft, etc...)" << endl;
  cout << "If the game is available we will display it for you." << endl;
  cout << "To exit, enter -1 \n" << endl;
  
  elem_t blank; // blank element

  // while user did not enter -1, search for game in BST
  while (searchKey != "-1")
    {
      cout << "Look for? ";
      cin >> searchKey;
      if(searchKey != "-1")
	{
	  elem_t found = tree.find(searchKey);
	  if(found == blank)
	    {
	      cout << "\n" << "\"" << searchKey << "\"" << " was not found in our library.\n" << endl;
	    }
	  else 
	    {
	      cout << "Found " << searchKey << ": " << found << endl;
	    }
	}
      else
	{
	  break;
	}

      // prompt to exit loop
      cout << "Continue Searching? (Enter any key): ";
      cin >> searchKey;
    }
  
  cout << "\nTHANK YOU FOR USING GAME SEARCH!!!\n" << endl; 
  
  return 0;
}
