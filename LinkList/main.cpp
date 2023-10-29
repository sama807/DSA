#include<iostream>
#include"LinkList.h"
#include "Node.h"
#include <string>
using namespace std;
template<typename T>
int findLen(LinkList<T>& list)
{
	Node<T>* p = list.getHead();
	int count = 0;
	while (p != nullptr)
	{
		count++;
		p = p->next;
	}
	return count;
}
template<typename T>
int findMid(LinkList<T>& list)
{
	Node<T>* p = list.getHead();
	int len = findLen(list);
	int count = 0;
	int m = len / 2;
	{
		while (count != m)
		{
			p = p->next;
			count++;
		}
		return p->info;
	}
}
//Task#3
template<typename T>
void removeDuplicate(LinkList<T>&list)
{
	
	Node<T>* pre = list.getHead();

	if (pre == nullptr)
		return;

	Node<T>* p = pre->next;

	while (p != nullptr)
	{
		if (pre->info == p->info)
		{
			pre->next = p->next;
			delete p;
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	pre = p;
}
template <typename T>
void printMergeLists(LinkList<T>& l1, LinkList<T>& l2)
{
	while (l1.getHead() != nullptr && l2.getHead() != nullptr)
	{
		if (l1.getHead()->info < l2.getHead()->info)
		{
			cout << l1.getHead()->info << " ";
			l1.removeAtHead();
		}
		else
		{
			cout << l2.getHead()->info << " ";
			l2.removeAtHead();
		}
	}

	//if (l1.getHead() == nullptr)
	//{
	//	l2.display();
	//	return;
	//}
	//if (l2.getHead() == nullptr)
	//{
	//	l1.display();
	//	return;
	//}

}
int main()
{
	LinkList<int> l;
	l.insertAtHead(3);
	l.insertAfter(4, 3);
	l.insertAfter(5, 4);
	l.removeAfter(4);
	/*cout << findMid(l) << "\n";
	cout<< findLen(l) << "\n";*/
	//l.removeBefore(3);
	l.display();
	cout << endl;
	/*removeDuplicate(l);
	l.display();*/
	/*LinkList<int>l2;

	l2.insertAtTail(-2);
	l2.insertAtTail(0);
	l2.insertAtTail(1);
	l2.insertAtTail(6);
	l2.insertAtTail(8);
	l2.display();
	cout << endl;*/
	//reverseTheList(l2);
	//printMergeLists(l, l2);
	//LinkList<int> l;
	//l.insertAtHead(3);

}