#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node* next;

};

template <typename T>
class Queue
{
public:

	Queue()
	{
		Head = new Node<T>;
		Tail = new Node<T>;
		Head->next = Tail;
		Tail->next = Head;
		length = 0;

	}

	~Queue()
	{
		Node<T>* deleteme = Head->next;
		for (int i = 0; i < length; i++)
		{
			Node<T>* node = deleteme->next;
			delete deleteme;
			deleteme = node;
		}
		delete Head;
		delete Tail;
	}

	void Push(T a)
	{

		if (length == 0)
		{
			Node<T>* temp = new Node<T>;
			temp->data = a;

			Head->next = temp;
			temp->next = Tail;
			Tail->next = temp;

			length++;
		}
		else
		{
			Node<T>* temp = new Node<T>;
			temp->data = a;

			Tail->next->next = temp;
			temp->next = Tail;
			Tail->next = temp;

			length++;

		}


	}

	void Pop()
	{
		Node<T>* removenode = Head->next;
		Head->next = removenode->next;
		length--;
		delete removenode;

	}

	void printlist()
	{
		Node<T>* node;
		node = Head->next;

		for (int i = 0; i < length; i++)
		{
			cout << i << "¹øÂ° : " << node->data << endl;
			node = node->next;
		}
	}

	int Size() { return length; }


private:
	Node<T>* Head;
	Node<T>* Tail;
	int length;
};

//#pragma region qutest
//
//void qutest()
//{
//	Queue<int> qu;
//
//	qu.Push(0);
//	qu.Push(1);
//	qu.Push(2);
//	qu.Push(3);
//	qu.Push(4);
//	qu.printlist();
//	qu.Pop();
//	qu.printlist();
//	qu.Pop();
//	qu.printlist();
//
//}
//#pragma endregion