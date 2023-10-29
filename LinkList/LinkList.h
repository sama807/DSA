#ifndef LINKLIST_H
#define LINKLIST_H
#include"Node.h"
template <typename T>
class LinkList
{
	Node<T>* head;
public:
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertBefore(T val, T key);
	void insertAfter(T val, T key);
	void removeAtHead();
	void removeAtTail();
	void removeBefore(T val);
	void removeAfter(T val);
	void display();
	Node<T>* getHead();
	void setHead(Node<T>* h);
	~LinkList();
	
	
};
#endif
