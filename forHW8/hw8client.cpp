// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Aaron Johnson
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include <iostream>
#include "htable.h"

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+name to add to the table. e.g. el_t X(30, "mary");
int main()
{
  htable table;
  el_t X; // blank element
  int searchKey;
  int tableKey;
  string tableName;
  
  // Loop: Interactively add about 20 keys and names to the table, making sure some of them  collide. (function add)
  // You can create el_t containing a key and name using a constructor.
  cout << "Enter a name and account number (0-999)" << endl;
  for(int i = 1; i <= 20; i++)
    {
      cout << "Client #" << i << " Name: ";
      cin >> tableName;
      cout << tableName << "'s account number: ";
      cin >> tableKey;
      el_t acc(tableKey, tableName);
      table.add(acc);
    }
 
  // DisplayTable.
  cout << endl;
  table.displayTable();
  cout << endl;
  
  // Loop: Interactively look up names using keys. (function find)
  // Cout the key + name if found else (blank element was returned) an error message.
  cout << endl;
  cout << "To exit, enter -1" << endl;
  cout << endl;
  
  while(searchKey != -1)
    {
      cout << "Look for? "; 
      cin >> searchKey;
      if(searchKey != -1)
	{
	  el_t found = table.find(searchKey);
	  if(X == found)
	    {
	      cout << searchKey << " not found." << endl;
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
    }
}
