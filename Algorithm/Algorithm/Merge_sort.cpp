#include <iostream>
#include <algorithm>

using namespace std;

int arr[8] = { 27,10,12,20,25,13,15,22 };

void merge_div(int, int);
void merge_sort(int, int, int);

int  Merge_sort()
{

	merge_div(0, 7);


	return 0;
}

void merge_div(int start, int end)
{
	int mid = (start + end) / 2;
	if (start < end) // �κ� �迭�� ���̰� 1���� ū ��� == ������ �� �ʿ��ϴ�~
	{
		merge_div(start, mid);
		merge_div(mid + 1, end);
		// ���� �ϰ� ������ ���� �Ŀ� �����ϸ鼭 �����ؾ� �ϴ� �� ��ġ�� sort�� ����!
		cout << "���� ��" << endl;

		for (int i = 0; i < 8; i++)
			cout << arr[i] << " ";
		cout << endl;

		cout << "start : " << start << " mid : " << mid << " end : " << end << endl;
		merge_sort(start, mid, end);

		cout << endl << "���� ��" << endl;

		for (int i = 0; i < 8; i++)
			cout << arr[i] << " ";
		cout << endl << endl;
	}

}

void merge_sort(int start, int mid, int end)
{
	int L, R, index;
	int tmp[8];
	copy(arr, &arr[8], tmp);

	L = start;
	R = mid + 1;
	index = start;

	while (L <= mid && R <= end)
	{
		if (arr[L] < arr[R])
			tmp[index++] = arr[L++];
		else
			tmp[index++] = arr[R++];
	}

	for (int i = 0; i <= mid - L; i++)
	{
		tmp[index + i] = arr[L + i];
	}

	// tmp�� arr�� ����
	copy(tmp, &tmp[8], arr);
}