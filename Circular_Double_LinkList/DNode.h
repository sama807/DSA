
#ifndef DNODE_H
#define DNODE_H

template <typename T>
struct DNode
{
	T info;
	DNode<T>* prev;
	DNode<T>* next;

	DNode()
	{
		prev = next = 0;
	}

	DNode(T val)
	{
		info = val;
		prev = next = 0;

	}

};

#endif;
#pragma once
