//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Linked List: Insert, Delete, Print
//------------------------------------------------------------
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <fstream>
// To detect  memory leak
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

class List
{
	public:
		// Constructor
		List();
		// Deconstructor
		~List();
		// Insert a node 
		bool insert(int);
		// Delete a node
		bool deleteNode(int);
		// Display the list
		void print();
		// Delete the list
		void free();
	private:
		struct Node
		{
			Node* next;
			int data;
		}; 
		Node *head;
};

#endif
