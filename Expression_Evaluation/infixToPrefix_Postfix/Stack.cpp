#include<iostream>
#include "Stack.h"
using namespace std;

template<typename T>
void Stack<T>::reSize(int newCap)
{
	capacity = newCap;

	T* temp = new T[newCap];
	for (int i = 0; i < top; i++)
	{
		temp[i] = data[i];
	}
	if(data)
		delete[]data;
	data = temp;
	temp = nullptr;
}

template<typename T>
Stack<T>::Stack()
{
	data = nullptr;
	capacity = 0;
	top = 0;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& ref)
{
	*this = ref;
}

template<typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& ref)
{
	if (this == &ref)
		return *this;
	
	this->~Stack();
	
	if (!ref.data)
		exit(0);
	
	reSize(ref.capacity);
	
	for (int i = 0; i < ref.top; i++)
		data[i] = ref.data[i];
	top = ref.top;

	return *this;
}

template<typename T>
Stack<T>::~Stack()
{
	if (!data)
	{
		return;
	}
	delete []data;
	data = nullptr;
	capacity = 0;
	top = 0;
}

template<typename T>
void Stack<T>::push(T value)
{
	if (capacity == 0)
		reSize(1);
	if (isFull())
	{
		reSize(capacity * 2);
	}

	data[top] = value;
	top++;
}
template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		//cout << "Stack is empty ";
		exit(0);
	}
	T value = data[--top];
	if (top>0 && top == capacity / 4)
	{
		reSize(capacity / 2);
	}
	return value;
}
template<typename T>
T Stack<T>::stackTop() const
{
	if (isEmpty())
	{
		cout << "Stack is empty ";
		exit(0);
	}
	return data[top - 1];
}
template<typename T>
bool Stack<T>::isFull() const
{
	if (top == capacity)
	{
		return true;
	}
	return false;
}
template<typename T>
bool Stack<T>::isEmpty() const
{
	if (top == 0)
	{
		return true;
	}
	return false;
}
template<typename T>
int Stack<T>::getCapacity() const
{
	return capacity;
}
template<typename T>
int Stack<T>::getNumberOfElements() const
{
	return top;
}

//template class Stack<int>;