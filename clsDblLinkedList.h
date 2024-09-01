#pragma once
#include <iostream>
using namespace std;
template <class T>
class clsDblLinkedList
{
protected:
	int _size = 0;
public:
	class Node
	{
	public:
		T _value;
		Node* _next;
		Node* _prev;
	};
	Node* Head = NULL;
	void InsertAtBeginning(T value)
	{
		Node* newNode = new Node();
		newNode->_value = value;
		newNode->_next = Head;
		newNode->_prev = NULL;
		
		if (Head != NULL)
		{
			Head->_prev = newNode;
		}
			Head = newNode;
			_size++;
	}
	void PrintList()
	{
		Node* Current = Head;
		while (Current != NULL)
		{
			cout << Current->_value << " ";
			Current = Current->_next;
		}
		cout << "\n";
		//cout << "NULL";
	}
	Node* Find(T value)
	{
	Node*Current = Head;
		while(Current != NULL)
		{
			if (Current->_value == value)
				return Current;
			Current = Current->_next;
		}
		return NULL;
	}
	void InsertAfter(Node* Current,T value)
	{
		Node* newNode = new Node();
		newNode->_value = value;
		newNode->_next = Current->_next;
		newNode->_prev = Current;
		if(Current->_next != NULL)
		{
		Current->_next->_prev = newNode;
		}
		Current->_next = newNode;
		_size++;
	}
	void InsertAtEnd(T value)
	{
		Node* newNode = new Node();
		newNode->_value = value;
		newNode->_next = NULL;
	    if(Head== NULL)
		{
			newNode->_prev = NULL;
			Head = newNode;
		}
		else
		{
			Node* Current = Head;
			while (Current->_next != NULL)
			{
				Current = Current->_next;
			}
			Current->_next = newNode;
			newNode->_prev = Current;
		}
		_size++;
	}
	void DeletNode(Node*& NodeToBeDeleted)
	{
		if (Head == NULL || NodeToBeDeleted==NULL)
			return;
		if (Head == NodeToBeDeleted)
		{
			Head = NodeToBeDeleted->_next;//To delete it if it's only one in the list
		}
		if (NodeToBeDeleted->_next != NULL)
		{
			NodeToBeDeleted->_next->_prev = NodeToBeDeleted->_prev;
		}
		if (NodeToBeDeleted->_prev != NULL)
		{
			NodeToBeDeleted->_prev->_next = NodeToBeDeleted->_next;
		}
		delete NodeToBeDeleted;
		_size--;
	}
	void DeletNodeAtBeginnig()
	{
		if (Head == NULL)
			return;
		Node* temp = Head;
		Head = Head->_next;
		if (Head != NULL)
		{
			Head->_prev = NULL;
		}
		delete temp;
		_size--;
	}
	void DeleteLastNode()
	{
		if (Head == NULL)
			return;
		if (Head->_next == NULL)
		{
			delete Head;
			Head = NULL;
			return;
		}
			
		Node* Current=Head;
	//To find the node before last node
		while (Current->_next->_next != NULL)
		{
			Current = Current->_next;//ponts to node before last node
		}
		Node* temp = Current->_next;//points to the last node
		Current->_next = NULL;
		delete temp;
		_size--;
	}
	int Size()
	{
		return _size;
	}
	bool Is_Empty()
	{
		return (_size == 0 ? true : false);
	}
	void Clear()
	{
		while (_size > 0)
		{
			DeletNodeAtBeginnig();
		}
	}
	void Reverse()
	{
		Node* temp = NULL;
		Node* Current = Head;
		while (Current != NULL)
		{
			temp = Current->_prev;
			Current->_prev = Current->_next;
			Current->_next = temp;
			Current = Current->_prev;
		}
		/* Before changing head, check for the cases like empty
	   list and list with only one node */
		if (temp != NULL)
			Head = temp->_prev;
	}
	Node* GetNode(int Index)
	{
		int counter = 0;
		Node* Current = Head;

		if (Index > _size - 1 || Index < 0)
			return NULL;

		while (Current!=NULL && (Current->_next != NULL))
		{
			if (counter == Index)
				break;

			Current = Current->_next;
			counter++;
		}
		return Current;
	}
	T GetItem(int index)
	{
		Node* NewItem = GetNode(index);
		return NewItem==NULL ?NULL : NewItem->_value;
	}
	bool UpdateItem(int index,T newValue)
	{
		Node* ItemNode = GetNode(index);
		if (ItemNode != NULL)
		{
			ItemNode->_value = newValue;
			return true;
		}
		else
		{
			return false;
		}
	}
	 bool InsertAfter(int index, int Insertedvalue)
	{
		Node* ItemNode = GetNode(index);
		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, Insertedvalue);//Mapping for index by itemNode
			return true;
		}
		else
			return false;
	}
	void PrintNodeDetails(Node* Head)
	{
		if (Head->_prev != NULL)
			cout << Head->_prev->_value;
		else
			cout << "NULL";

		cout << "<-->" << Head->_value << "<-->";
		if (Head->_next != NULL)
			cout << Head->_next->_value << endl;
		else
			cout << "NULL";
	}
	/*void PrintNodeDetails(Node* Head)
	{
		if (Head->_prev != NULL)
			cout << Head->_prev->_value;
		else
			cout << "NULL";

		cout << "<-->" << Head->_value << "<-->";
		if (Head->_next != NULL)
			cout << Head->_next->_value << endl;
		else
			cout << "NULL";
	}
	void PrintListDetails(Node* Head)
	{
		cout << "\n\n";
		while(Head != NULL)
		{
			PrintNodeDetails(Head);
			Head = Head->_next;
		}
	}*/
	

};