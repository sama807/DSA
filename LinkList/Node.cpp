#include"Node.h"
#include<iostream>
using namespace std;
template <typename T>
Node<T>:: Node()
{
	next = nullptr;
	info = 1;
}
template <typename T>
Node<T>::Node(T val)
{
	info = val;
	next = nullptr;
}
//template <typename T>
//Node<T>:: ~Node()
//{
//	if (next)
//		delete;
//	next = nullptr;
//}