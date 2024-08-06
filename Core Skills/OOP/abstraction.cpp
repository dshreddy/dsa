// making something not so simple look simple
// Types of Abstraction:
// Data abstraction – This type only shows the required information about the data and hides the unnecessary data.
// Control Abstraction – This type only shows the required information about the implementation and hides unnecessary information.

/*
We can easily implement abstraction using the above two features provided by access specifiers. Say, the members that define the internal implementation can be marked as private in a class. And the important information needed to be given to the outside world can be marked as public. And these public members can access the private members as they are inside the class. 
*/

#include <iostream>
using namespace std;

class implementAbstraction {
private:
	int a, b;

public:
	// method to set values of
	// private members
	void set(int x, int y)
	{
		a = x;
		b = y;
	}

	void display()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}
};

int main()
{
	implementAbstraction obj;
	obj.set(10, 20);
	obj.display();
	return 0;
}
