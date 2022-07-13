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
class LinkedList
{
public:
	LinkedList()
	{
		Head = new Node<T>;
		Tail = new Node<T>;
		Head->next = Tail;
		Tail->next = Head;
		length = 0;
		
	}

	~LinkedList()
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

	void addhead(T a)
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
			temp->next = Head->next;
			Head->next = temp;
			length++;

		}

	}

	void addtail(T a)
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
			Tail->next -> next = temp;
			temp->next = Tail;
			Tail->next = temp;
			length++;

		}
	}

	void Insert(T a, int idx)
	{
		Node<T>* node = Head->next;

		for (int i = 0; i < idx-1; i++)
		{
			node = node->next;
		}
		Node<T>* addnode = new Node<T>;
		addnode->data = a;
		addnode->next = node->next;
		node->next = addnode;
		length++;
	}

	void removehead()
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

#pragma region Test
void test()
{
	LinkedList<int> li;

	li.addhead(0);
	li.printlist();
	li.addtail(1);
	li.printlist();
	cout << endl;
	li.addtail(2);
	li.addtail(3);
	li.addtail(4);
	li.printlist();
	cout << endl;
	li.Insert(6, 1);
	li.printlist();
	cout << endl;
	li.removehead();
	li.printlist();
	cout << endl;

}
#pragma endregion