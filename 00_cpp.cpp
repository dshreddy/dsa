#include <bits/stdc++.h>
using namespace std;

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

struct Passenger {

  string name;
  MealType mealPref;
  bool isFreqFlyer;
  string freqFlyerNo;
};

// We will follow the convention of indicating user-defined types by capitalizing the first character of their names.

typedef char *BufferPtr;   // type BufferPtr is a pointer to char
typedef double Coordinate; // type Coordinate is a double
BufferPtr ptr;             // ptr is a pointer to char
Coordinate x, y;           // x and y are of type double

/*
C++ statements are enclosed in curly braces ({...}), they define a block.
Variables and types that are declared within a block are only accessible from
within the block.
*/

// A namespace is a mechanism that allows a group of related names to be defined in one place.
namespace myglobals {
int cat;
string dog = "bow wow";
} 

int main() {

  // Arrays & Pointers, Pointer Arithematic
  int a[] = {1, 2, 3};
  int b[] = {4, 5, 6};

  cout << (a == b) << endl; // compares if the ptr's to a[0] & b[0] are same or not

  // a[] is same as *a (value at the address stored in the pointer a)
  // a[i] is same as *(a+i) (value at the address a+i)
  //*********** once declared you can't change the size of an array *********************
  
  //-------------- C style Structures --------------------

  Passenger pass = {"John Smith", VEGETARIAN, true, "293145"};
  pass.name = "Pocahontas";

  /*
  Let p be a pointer to a Passenger structure. This implies that *p refers to the actual structure; 
  hence, we could access one of its members, say the mealPref field, using the expression (*p).mealPref.
  Because complex objects   like structures are often allocated dynamically, C++ provides a shorter way to
  access members using the “->” operator.
  ******************* pointer_name->member is equivalent to (*pointer_name).member **********************
  */

  Passenger *p;
  p = new Passenger;
  p->name = "Pocahontas";
  p->mealPref = REGULAR;
  p->isFreqFlyer = false;
  p->freqFlyerNo = "NONE";

  /*
  This new passenger object continues to exist in the free store until it is
  explicitly deleted by a process that is done using the delete operator, which
  destroys the object and returns its space to the free store.
  */
  delete p;

  // The delete operator should only be applied to objects that have been allocated through new.

  //C++ does not provide automatic garbage collection. 
  //This means that C++ programmers have the responsibility of explicitly deleting all dynamically allocated objects. 

  char *buffer = new char[500];
  buffer[3] = 'a';
  delete[] buffer;

  // Arrays allocated in this manner CAN NOT be deallocated using the standard delete operator. 
  // INSTEAD, the operator delete [] is used. If an object is allocated with new, 
  // it should eventually be deallocated with delete. (To avoid memory leaks)

  // We can access an object x in namespace group, using the notation group::x
  myglobals::cat = 10;
  cout << myglobals::cat << endl;

  // If we are repeatedly using variables from the same namespace, it is
  // possible to avoid entering namespace specifiers by telling the system that
  // we want to “use” a particular specifier.
  using std::string;         // makes just std::string accessible
  using namespace myglobals; // makes all of myglobals accessible
  return 0;
}
