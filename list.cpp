#include "list.h"


List::List()
{
	head = NULL;
}


// Deconstructor
List::~List()
{
	free();
}


// Insert a node in the list
bool List::insert(int data)
{
	// Create new node
	Node* newNode = new Node;
	// Out of memory, bail
	if (newNode == NULL)
		return false;
	newNode->data = data;


	// Check if newNode needs to be inserted before the head
	if (head == NULL || newNode->data < head->data)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		Node* prev = head;
		Node* cur = head->next;


		// Travserse the list to find the correct location
		while (cur != NULL && cur->data < data)
		{
			prev = cur;
			cur = cur->next;
		}
		// Add the node
		newNode->next = cur;
		prev->next = newNode;


	}
	return true;
}

// Recursive insert
void List::rInsert(int data)
{
	rInsertHelper(head,data);
}

// Recursive insert helper
void List::rInsertHelper(Node *& head, int data)
{
	if (head == NULL || data < head->data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}
	else
		rInsertHelper(head->next,data);

}
// Print the list
void List::print()
{
	Node* cur = head;
	while (cur != NULL)
	{
		cout << cur->data << " -> ";
		cur = cur->next;
	}
	cout << "NULL" << endl;


}


// Delete a node from the list
bool List::deleteNode(int data)
{
	// List is empty
	if (head == NULL)
		return false;
	// Data is in the head
	if (head->data == data)
	{
		Node* cur = head->next;
		delete head;
		head = cur;
	}
	else
	{
		Node* prev = head;
		Node* cur = head->next;
		while (cur != NULL && data != cur->data)
		{
			prev = cur;
			cur = cur->next;
		}
		if (cur != NULL)
		{
			prev->next = cur->next;
			delete cur;
			cur = NULL;
		}
	}
	return true;
}

// Remove all node with a particular number
void List::removeAll(int data)
{
	if (head == NULL)
		return;
	Node* tmp = head;
	// Head of the list contains the number to be removed
	while (tmp != NULL && tmp->data == data)
	{
		tmp = head;
		head = tmp->next;
		delete tmp;
		tmp = NULL;
	}
	Node* prev = head;
	Node* cur = head->next;
	// Now travserse and remove all nodes
	while (cur->next != NULL)
	{
		if (cur->data == data)
		{
			prev->next = cur->next;
			delete cur;
			cur = prev->next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}

}
// Delete the list / Deallocate memory
void List::free()
{
	if (head != NULL)
	{
		Node* cur;
		while (head->next != NULL)
		{
			cur = head->next;
			delete head;
			head = cur;
		}
		head = NULL;
	}
}


int main(void)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(141);


	List l1;
	// Test recursive insert
	for (int i = 5; i > 0; i--)
	{
		l1.rInsert(i);
	}

	// Testing iterative insert
	for (int i = 0; i >= -5; i--)
	{
		l1.insert(i);
	}
	l1.insert(4);
	l1.insert(4);
	l1.insert(4);
	// Test removeAll
	l1.removeAll(4);
	// Test Delete
	l1.deleteNode(1);
	l1.deleteNode(3);
	l1.deleteNode(3);
	l1.deleteNode(-3);
	l1.deleteNode('e');
	l1.print();
	l1.free();
	l1.print();


	// Detect memory  leak
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

