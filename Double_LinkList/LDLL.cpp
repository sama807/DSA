
#include "LDLL.h"
#include <iostream>
using namespace std;


template <typename T>
LDLL<T>::LDLL()
{
	head = 0;
}

template <typename T>
void LDLL<T>::insertAtHead(T val)
{

	if (!head)
	{
		head = new DNode<T>(val);
		return;
	}

	DNode<T>* x = new DNode<T>(val);
	x->next = head;
	head->prev =x;
	head= x;
}

template <typename T>
void LDLL<T>::insertAtTail(T val)
{
	DNode<T>* x = new DNode<T>(val);
	DNode<T>* p = head;

	if (!head)
	{
		head = new DNode<T>(val);
		return;
	}
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->next = x;
	x->prev = p;
}

template <typename T>
void LDLL<T>::insertAfter(T key, T val)
{
	DNode<T>* p = head;
	DNode<T>* x = new DNode<T>(val);
	
	while (p != nullptr && p->info != key)
	{
		p = p->next;
		if (!p)
			return;
	}

	x->next = p->next;
	p->next = x;
	if (x->next != nullptr)
		x->next->prev = x;
	x->prev = p;
}

template <typename T>
void LDLL<T>::insertBefore(T key, T val)
{
	if (!head)
		return;
	if (head->info == key)
	{
		DNode<T>* p = head;
		return;
	}
	DNode<T>* p = head;
	while (p != nullptr && p->info != key)
	{
		p = p->next;
		
	}
	if (!p && p->info!=key)
		return;
	DNode<T>*x = new DNode<T>(val);
	x->next = p;
	x->prev = p->prev;
	p->prev = x;
	x->prev->next = x;
	
}

template <typename T>
void LDLL<T>::removeAtHead()
{
	if (!head)
	{
		return;
	}
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
	}
	DNode<T>* p = head;
	head = head->next;
	head->prev = nullptr;
	delete p;
}

template <typename T>
void LDLL<T>::removeAtTail()
{
	DNode<T>* p = head;

	if (!head)
		return;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	if (p->prev == nullptr)
	{
		head = nullptr;
		delete p;
		return;
	}
	p->prev->next = nullptr;
	delete p;
}

template <typename T>
void LDLL<T>::removeBefore(T key)
{
	if (!head)
		return;
	DNode<T>* p = head;
	if (head->info == key)
		return;
	while (p->next != nullptr && p->info != key)
	{
		p = p->next;
	}
	if (p->next == nullptr && p->info != key)
		return;

	DNode<T>* x = p->prev;
	p->prev = x ->prev;
	if (x->prev == nullptr)
	{
		head = p;
		delete x;
		return;
	}
	x->prev->next = p;
	delete x;
}

template <typename T>
void LDLL<T>::removeAfter(T key)
{
	if (!head)
		return;

	DNode<T>* p = head;
	while (p->next != nullptr && p->info != key)
	{
		p = p->next;
	}

	if (p->next == nullptr)
		return;
	DNode<T>* x = p->next;
	p->next = p->next->next;
	p->next->prev = p;
	delete x;

}

template <typename T>
void LDLL<T>::remove(T key)
{
	DNode<T>* p = head;
	if (head->info == key)
	{
		removeAtHead();
	}
	while (p != nullptr && p->info != key)
	{
		p = p->next;
	}
	if (p->next == nullptr)
	{
		p->prev->next = nullptr;
		delete p;
		return;
	}
	p->next->prev = p->prev;
	p->prev->next = p->next;
	delete p;
}

template <typename T>
void LDLL<T>::display()
{
	DNode<T>* p = head;
	while (p != nullptr)
	{
		cout << p->info << " ";
		p = p->next;
	}
	
	
}
