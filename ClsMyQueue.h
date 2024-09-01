#pragma once
#include<iostream>
#include"clsDblLinkedList.h" 
using namespace std;


template<class T>
class ClsMyQueue
{
protected:
	clsDblLinkedList<T>_MyList;
public:

	void Print()
	{
		_MyList.PrintList();
	}
	void Push(T item)
	{
		_MyList.InsertAtEnd(item);
	}
	void POP()
	{
		_MyList.DeletNodeAtBeginnig();
	}
	int Size()
	{
		return _MyList.Size();
	}
	T Front()
	{
		return _MyList.GetItem(0);
	}
	T Back()
	{
		return _MyList.GetItem(Size() - 1);
	}
	bool IsEmpty()
	{
		return _MyList.Is_Empty();
	}
	
	/// //////////////////////////////////////////////////////////
	
	T GetItem(T index)
	{
		return _MyList.GetItem(index);
	}
	void Reverse()
	{
		_MyList.Reverse();
	}
	void UpdateItem(T Index,T NewValue)
	{
		_MyList.UpdateItem(Index, NewValue);
	}
	void InsertAfter(T ExistValue,T NewValue)
	{
		_MyList.InsertAfter(ExistValue, NewValue);
	}
	void InsertAtFront(T value)
	{
		_MyList.InsertAtBeginning(value);
	}
	void InsertAtBack(T value)
	{
		_MyList.InsertAtEnd(value);
	}
	void Clear()
	{
		_MyList.Clear();
	}
	//////////////////////////////////////////////////
};
