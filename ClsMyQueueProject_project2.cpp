#include <iostream>
#include"ClsMyQueue.h"
using namespace std;

int main()
{
	ClsMyQueue<int>MyQueue;
	MyQueue.Push(10);
	MyQueue.Push(20);
	MyQueue.Push(30);
	MyQueue.Push(40);
	MyQueue.Push(50);
	
	cout << "My Queue is :" << endl;
	MyQueue.Print();

	cout <<"size "<< MyQueue.Size() << endl;
	cout <<"front element"<< MyQueue.Front() << endl;
	cout <<"Back Element"<<MyQueue.Back() << endl;

	 MyQueue.POP();
	 cout << "My Queue after popping is :" << " ";
	 MyQueue.Print();

	cout<<"The item is "<< MyQueue.GetItem(3)<<endl;

	MyQueue.Reverse();
	MyQueue.Print();

	MyQueue.UpdateItem(3, 800);
	MyQueue.Print();

	MyQueue.InsertAtFront(1000);
	MyQueue.Print();

	MyQueue.InsertAtBack(2000);
	MyQueue.Print();

	MyQueue.Clear();
	cout << "The queue is : " << endl;
	MyQueue.Print();


}


