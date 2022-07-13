#include <iostream>
#include <algorithm>

using namespace std;

int heap[8] = { 27,10,12,20,25,13,15,22 };

void heapify(int, int);
void swap(int, int);
int getParent(int child) { return (child - 1) / 2; }
void heapSort(int);

int  Heap_sort()
{
	cout << "���� ��" << endl;

	for (int i = 0; i < 8; i++)
		cout << heap[i] << " ";
	cout << endl;
	heapSort(8);

	cout << "���� ��" << endl;

	for (int i = 0; i < 8; i++)
		cout << heap[i] << " ";
	cout << endl;


	return 0;
}

void swap(int i, int j)
{
	int temp = heap[i];
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
			parent = largest; // �׸��� ������ �Ͼ���ϱ� ���� Ʈ���˻縦 ���ؼ� parent���� ������ �ڽ� ��� ������ �ٲٱ�~
		}
		else
			return;

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