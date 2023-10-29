#ifndef NODE_h
#define NODE_h

template <typename T>
struct Node
{
	T info;
	Node<T>* next;
public:

	Node();
	Node(T val);
	//~Node();
};
#endif
