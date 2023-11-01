
#include "CDLL.h"
#include <iostream>
using namespace std;

template <typename T>
CDLL<T>::CDLL()
{
	head = 0;
}

template <typename T>
void CDLL<T>::insertAtHead(T val)
{
	DNode<T>* x = new DNode<T>(val);

	if (!head)
	{
		head = x;
		head->next = x;
		head->prev = x;
		return;
	}

	x->next = head;
	x->prev = head->prev;
	head->prev = x;
	x->prev->next = x;
	head = x;
}

template <typename T>
void CDLL<T>::insertAtTail(T val)
{
	DNode<T>* x = new DNode<T>(val);
	if (!head)
	{
		head = x;
		head->next = x;
		head->prev = x;
		return;
	}

	x->prev = head->prev;
	x->next = x->prev->next;
	x->prev->next = x;
	head->prev = x;
}

template <typename T>
void CDLL<T>::insertAfter(T key, T val)
{
	DNode<T>* p = head;

	do
	{
		if (p->info == key)
		{
			DNode<T>* x = new DNode<T>(val);
			p->next->prev = x;
			x->next = p->next;
			p->next = x;
			x->prev = p;
			return;
		}

		p = p->next;

	} while (p != head);

}

template <typename T>
void CDLL<T>::insertBefore(T key, T val)
{
	DNode<T>* p = head;

	do
	{
		if (p->info == key)
		{
			DNode<T>* x = new DNode<T>(val);
			x->next = p;
			x->prev = p->prev;
			p->prev = x;
			x->prev->next = x;

			if (head == p)
			{
				head = x;
			}
			return;
		}

		p = p->next;
	} while (p != head);

}

template <typename T>
void CDLL<T>::removeAtHead()
{
	if (!head)
	{
		return;
	}

	DNode<T>* x = head;
	head->next->prev = head->prev;
	head->prev->next = head->next;
	head = head->next;
	delete x;
	x = nullptr;

}

template <typename T>
void CDLL<T>::removeAtTail()
{
	DNode<T>* p = head->prev;

	if (!head)
		return;
	if (head->prev == head->next)
	{
		delete head;
		return;
	}

	head->prev = head->prev->prev;
	head->prev->next = head;
	delete p;
	p = nullptr;
}

template <typename T>
void CDLL<T>::removeBefore(T val)
{
	DNode<T>* p = head;

	do
	{
		if (p->info == val)
		{
			DNode<T>* x = p->prev;
			p->prev = p->prev->prev;
			p->prev->next = p;
			if (x == head)
			{
				head = head->next;
			}

			delete x;
			x = 0;
			return;
		}

		p = p->next;
	} while (p != head);
}

template <typename T>
void CDLL<T>::removeAfter(T val)
{
	if (!head)
		return;

	DNode<T>* p = head;

	do
	{
		if (p->info == val)
		{
			DNode<T>* x = p;
			x = p->next;
			p->next = p->next->next;
			p->next->prev = p;
			if (x == head)
			{
				head = x->next;
			}

			delete x;
			x = 0;
			return;
		}

		p = p->next;
	} while (p != head);

}

template <typename T>
void CDLL<T>::remove(T val)
{
	DNode<T>* p = head;

	do
	{
		if (p->info == val)
		{
			DNode<T>* temp = head->next;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			if (p == head)
			{
				head = temp;
			}
		
			return;
		}

		p = p->next;
	} while (p != head);
}

template <typename T>
void CDLL<T>::display()
{
	DNode<T>* p = head;

	do
	{
		cout << p->info << " ";
		p = p->next;
	} while (p != head);
}
