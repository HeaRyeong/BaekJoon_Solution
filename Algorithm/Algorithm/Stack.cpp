#include<iostream>
#include<algorithm>

using namespace std;

template <typename T>
class Stack
{
public:

	
	Stack() : top(0), capacity(5)
	{
		data = new T[capacity];
	}

	Stack(int capa) : top(0)
	{
		capacity = capa;
		data = new T[capacity];
	}
	
	~Stack()
	{
		delete data;
	}
	

	T Push(T a)
	{
		if (capacity <= top) // 확장 이전
		{
			Resize();
		}

		data[top++] = a;

		return a;

	}

	
	void Resize() // 기존 사이즈의 2배사이즈로 확장
	{
		T* temp;
		T* removeme;
		temp = new T[capacity * 2];
		copy(data, data + top, temp);
		removeme = data;
		data = temp;
		capacity = capacity * 2;
		delete removeme;

	}

	T Pop() { return data[top--]; }
	int Top() { return data[top-1]; }
	int Size() { return top; }
	int Capacity() { return capacity; }

private:
	T* data;
	int capacity;
	int top;
};


#pragma region Testcode
void testStack()
{
	Stack<int> s;

	cout << "s.Size() : " << s.Size() << endl;
	cout << "s.Capacity() : " << s.Capacity() << endl;

	cout << "s.Push(5) : " << s.Push(5) << endl;
	cout << "s.Size() : " << s.Size() << endl;
	cout << "s.Top() : " << s.Top() << endl;
	
	cout << "s.Push(4) : " << s.Push(4) << endl;
	
	cout << "s.Push(3) : " << s.Push(3) << endl;
	
	cout << "s.Push(2) : " << s.Push(2) << endl;
	
	cout << "s.Push(1) : " << s.Push(1) << endl;
	
	cout << "s.Push(0) : " << s.Push(0) << endl;
	cout << "s.Size() : " << s.Size() << endl;
	cout << "s.Capacity() : " << s.Capacity() << endl;
	cout << "s.Top() : " << s.Top() << endl;
	
}
#pragma endregion

