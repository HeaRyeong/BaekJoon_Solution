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
	cout << "정렬 전" << endl;

	for (int i = 0; i < 8; i++)
		cout << heap[i] << " ";
	cout << endl;
	heapSort(8);

	cout << "정렬 후" << endl;

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
	int LC; // 왼쪽 자식 인덱스
	int RC; // 오른쪽 자식 인덱스
	int largest; // 현재 가장 큰 수의 인덱스

	while ((parent * 2) + 1 <= last) // parent*2 +1 은 부모 인덱스 기준 왼쪽 자식 노드 인덱스! 
	{
		LC = (parent * 2) + 1;
		RC = (parent * 2) + 2;
		// 현재 가장 큰 인덱스는 부모 인덱스라고 가정하고 largest 초기값 설정 (부모가 최대가 아닐 수 도 있음 !==> 아직 최대 힙이 아니기 때문 )
		largest = parent;

		if (heap[LC] > heap[largest]) // 왼쪽 자식의 경우는 while문에서 범위 검사를 이미 통과함!
			largest = LC;

		if (heap[RC] > heap[largest] && RC <= last) // 오른쪽 자식의 경우는 범위 검사를 해줘야한다~
			largest = RC;

		if (largest != parent) // 만약 최대 값 인덱스가 부모가 아닌 경우!
		{
			// 인덱스가 옳은 자리를 찾아가게 스왑이 일어나야함~
			swap(largest, parent);
			parent = largest; // 그리고 스왑이 일어났으니까 하위 트리검사를 위해서 parent값을 원래의 자식 노드 값으로 바꾸기~
		}
		else
			return;

	}

}

void heapSort(int size)
{
	if (size < 2)
		return;

	// 먼저 배열을 최대 힙으로 만들기
	int parent = getParent(size - 1);

	for (int i = parent; i >= 0; i--)
	{
		heapify(i, size - 1);
	}

	// 정렬하기

	for (int i = size - 1; i > 0; i--) // 점점 작아지는 서브 트리!
	{
		swap(0, i); // 루트 노드와 마지막 노드 swap
		heapify(0, i - 1); // 부분 트리 재정렬 (last는 점점 줄어들기 때문에 i-1 )
	}
}