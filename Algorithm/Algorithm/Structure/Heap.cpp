#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

template <typename T>
class Heap
{
public:
	Heap() : size(0)
	{

	}

	~Heap()
	{

	}

	void swap(int i, int j)
	{
		T temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}

	void heapify(int parent, int last)
	{
		int LC; // ���� �ڽ� �ε���
		int RC; // ������ �ڽ� �ε���
		int largest; // ���� ���� ū ���� �ε���

		while ((parent * 2) + 1 <= last) // parent*2 +1 �� �θ� �ε��� ���� ���� �ڽ� ��� �ε���! 
		{
			LC = (parent * 2) + 1;
			RC = (parent * 2) + 2;
			// ���� ���� ū �ε����� �θ� �ε������ �����ϰ� largest �ʱⰪ ���� (�θ� �ִ밡 �ƴ� �� �� ���� !==> ���� �ִ� ���� �ƴϱ� ���� )
			largest = parent;

			if (heap[LC] > heap[largest]) // ���� �ڽ��� ���� while������ ���� �˻縦 �̹� �����!
				largest = LC;

			if (heap[RC] > heap[largest] && RC <= last) // ������ �ڽ��� ���� ���� �˻縦 ������Ѵ�~
				largest = RC;

			if (largest != parent) // ���� �ִ� �� �ε����� �θ� �ƴ� ���!
			{
				// �ε����� ���� �ڸ��� ã�ư��� ������ �Ͼ����~
				swap(largest, parent);
				parent = 0;
			}
			else
				parent++;

		}
	}

	void heapSort(int size)
	{
		if (size < 2)
			return;

		// ���� �迭�� �ִ� ������ �����
		int parent = getParent(size - 1);

		for (int i = parent; i >= 0; i--)
		{
			heapify(i, size - 1);
		}

		// �����ϱ�

		for (int i = size - 1; i > 0; i--) // ���� �۾����� ���� Ʈ��!
		{
			swap(0, i); // ��Ʈ ���� ������ ��� swap
			heapify(0, i - 1); // �κ� Ʈ�� ������ (last�� ���� �پ��� ������ i-1 )
		}
	}

	void insert(T a)
	{
		if (Size() >= 100)
			cout << "������ �����մϴ�" << endl;
		else
		{
			heap[size] = a;
			heapify(0, Size());
			cout << "insert Size : " << Size() << endl;
			size++;
		}

	}

	void remove(int idx) // �����ϰ���� ��� ��ȣ
	{
		if (Size() == -1)
		{
			cout << "�̹� �� ������ϴ�" << endl;
			return;
		}

		if (idx == Size())
		{
			size--;
			return;
		}
		else
		{
			memcpy(&heap[idx], &heap[idx + 1], sizeof(T) * ((size - 1) - idx));
			size--;
			heapify(0, Size());
			return;
		}

	}

	void print()
	{
		cout << "Heap print" << endl;

		if (Size() == -1)
		{
			cout << "�� Heap �Դϴ�" << endl;
			return;
		}

		for (int i = 0; i < Size(); i++)
			cout << heap[i] << " ";
		cout << endl;
	}

	int Size() { return size; }
	int getParent(int child) { return (child - 1) / 2; }



private:
	T heap[100];
	int size;

};

//void testing()
//{
//	Heap<int> a;
//
//	a.print();
//	a.insert(1);
//	cout << "Size : " << a.Size() << endl;
//	a.print();
//	cout << endl;
//
//	a.insert(6);
//	cout << "Size : " << a.Size() << endl;
//	a.print();
//	cout << endl;
//
//	a.insert(3);
//	cout << "Size : " << a.Size() << endl;
//	a.print();
//	cout << endl;
//
//	a.insert(4);
//	cout << "Size : " << a.Size() << endl;
//	a.print();
//	cout << endl;
//
//	a.insert(12);
//	cout << "Size : " << a.Size() << endl;
//	a.print();
//	cout << endl;
//
//	a.insert(34);
//	cout << "Size : " << a.Size() << endl;
//	a.print();
//	cout << endl;
//
//	a.remove(4);
//	cout << "Size : " << a.Size() << endl;
//	a.print();
//	cout << endl;
//
//	a.remove(2);
//	cout << "Size : " << a.Size() << endl;
//	a.print();
//	cout << endl;
//
//	a.heapSort(a.Size());
//	cout << "Size : " << a.Size() << endl;
//	a.print();
//	cout << endl;
//	return;
//}