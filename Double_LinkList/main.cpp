
#include "LDLL.h"
#include <iostream>
using namespace std;

int main()
{
	LDLL<int> l;
	l.insertAtHead(1);
	l.insertAtHead(2);
	l.insertAtHead(3);
	l.insertAtHead(4);
	l.insertAtTail(5);
	l.insertAtTail(6);

	l.insertAfter(3, 7);
	l.insertBefore(3, 10);
	l.remove(10);
	l.removeAfter(4);
	l.removeAtHead();
	l.removeAtTail();
	l.removeBefore(5);
	l.display();


	return 0;

}

