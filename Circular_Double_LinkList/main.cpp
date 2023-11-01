#include<iostream>
using namespace std;
#include "CDLL.h"
int main()
{
	CDLL<int>a;
	a.insertAtHead(1);
	a.insertAtTail(4);
	a.insertBefore(4,7);
	a.insertAfter(4, 8);
	a.display();
}