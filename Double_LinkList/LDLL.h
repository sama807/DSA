#ifndef LDLL_H
#define LDLL_H

#include "DNode.h"

template <typename T>
class LDLL
{
	DNode<T>* head;

public:

	LDLL();
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeAtHead();
	void removeAtTail();
	void removeBefore(T val);
	void removeAfter(T val);
	void remove(T val);
	void display();
};

#endif;
#pragma once
