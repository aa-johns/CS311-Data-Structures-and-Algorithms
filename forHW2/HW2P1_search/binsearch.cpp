using namespace std;
#include <iostream>

//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Aaron Johnson
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
int binarySearch(int L[], int x, int first, int last) 
{
 int middle = (first+last)/2;  // note that if first == last, there is only one element left
 if (x == L[middle])
   {
     cout << "comparing against the element in slot " << middle <<endl;
     return middle;  // found x at location middle
   }
 else if (first == last) //if cannot be fount, return -1
   {
     return -1;
   }
 else if (x < L[middle])
   {
     cout << "comparing against the element in slot " << middle << endl; 
     last  = middle - 1; // go to first half
   }
 else if (x > L[middle])
   {
     cout << "comparing against the element in slot " << middle << endl;
     first = middle + 1; // go to second half
   }
 return binarySearch(L, x, first, last); // recursive call
}


int main()
{ 
  int A[10]; // <---- match with n (if need to reuse program)
  int findthis;  // to look for this
  int myfirst = 0;
  int n = 10; // number of array elements
  int mylast = n-1;

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> findthis;

  // Call binarySearch here to look for findthis in A
  int respos = binarySearch(A,findthis,myfirst,mylast);

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found " << findthis << " in position " << respos+1 << endl;
}
