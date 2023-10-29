#include "LinkList.h"
#include<iostream>
#include"Node.h"
using namespace std;
template<typename T>
void LinkList<T>::insertAtHead(T val)
{
	Node<T>* p = new Node<T>(val);
	p->next = head;
	head = p;
}
template<typename T>
void LinkList<T>:: insertAtTail(T val)
{
	Node<T>* x = new Node<T>(val);
	if (head == nullptr)
	{
		head = x;
		return;
	}
	Node<T>* p = head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->next = x;
	x->next = nullptr;
	
}
template<typename T>
void LinkList<T>::insertBefore(T val, T key)
{
	Node<T>* pre = head;
	Node<T>* p = head->next;

	//if list contains only one node
	if (head->info == key) 
	{
		insertAtHead(val);
		return;
	}
	while (p!= nullptr)
	{
		if (p->info ==key)
		{
			Node<T>* x = new Node<T>(val);
			x->next = p;
			pre->next = x;
			return;
		}
		pre = p;
		p = p->next;
	}
	cout << "Key not found\n";

}
template<typename T>
void LinkList<T>::insertAfter(T val, T key)
{
	Node<T>* p = head;

	//List contain only one node
	if (head->info == key) 
	{
		insertAtTail(val);
		return;
	}
	while (p != nullptr)
	{
		if (p->info == key)
		{
			//Create new node
			Node<T>* x = new Node<T>(val);
			Node<T>* aft = p->next;
			p->next = x;
			x->next = aft;
			return;
		}
		p = p->next;
	}
	cout << "Key not found";
}
template<typename T>
void LinkList<T>:: removeAtHead()
{
	Node<T>* p = head;
	if (!head)
		return;
	head = head->next;
	delete p;
}
template<typename T>
void LinkList<T>::removeAtTail()
{
	Node<T>* p = head;
	if (!head)
		return;
	if (head->next == nullptr)
	{
		delete head;
		head = 0;
		return;
	}
	while (p->next->next != nullptr)
	{
		p = p->next;
	}
	delete p->next;
	p->next = nullptr;
}
template<typename T>
void LinkList<T>:: display()
{
	Node<T>* p = head;
	while (p != nullptr)
	{
		cout << p->info<<" ";
		p = p->next;
	}
}
template<typename T>
void LinkList<T>:: removeBefore(T key)
{
	Node<T>* ind = head;
	Node<T>* preInd = head;
	Node<T>* prePreInd = head;
	if (!head)
		return;
	if (head->info == key)
		return;
	if (head->next->info == key)
	{
		removeAtHead();
		return;
	}
	while (ind != nullptr && ind->info != key)
	{
		prePreInd = preInd;
		preInd = ind;
		ind = ind->next;
	}
	delete preInd;
	preInd = nullptr;
	prePreInd->next = ind;
}
template<typename T>
void LinkList<T>::removeAfter(T key)
{
	Node<T>* i = head;
	while (i != nullptr && i->info != key)
		i = i->next;

	if (i == nullptr)
		return;
	if (i->next == nullptr)
		return;

	Node <T>* temp = i->next;
	i->next = i->next->next;

	delete temp;
	temp = nullptr;
}
template<typename T>
Node<T>* LinkList<T>::getHead()
{
	return head;
}
template<typename T>
LinkList<T>:: ~LinkList()
{
	Node<T>* p = head;
	while (p != nullptr)
	{
		Node<T>* temp = p;
		p = p->next;
		delete temp;
	}
}
template<typename T>
void LinkList<T>:: setHead(Node<T>* h)
{
	head = h;
}