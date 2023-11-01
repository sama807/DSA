
#ifndef CDLL_H
#define CDLL_H

#include "DNode.h"

template <typename T>
class CDLL
{
	DNode<T>* head;
public:
	CDLL();
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
