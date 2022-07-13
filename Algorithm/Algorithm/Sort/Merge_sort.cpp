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
	if (start < end) // 부분 배열이 길이가 1보다 큰 경우 == 분할이 더 필요하다~
	{
		merge_div(start, mid);
		merge_div(mid + 1, end);
		// 분할 하고 나서는 이제 후에 정렬하면서 병합해야 하니 이 위치에 sort가 들어간다!
		cout << "정렬 전" << endl;

		for (int i = 0; i < 8; i++)
			cout << arr[i] << " ";
		cout << endl;

		cout << "start : " << start << " mid : " << mid << " end : " << end << endl;
		merge_sort(start, mid, end);

		cout << endl << "정렬 후" << endl;

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

	// tmp를 arr에 복사
	copy(tmp, &tmp[8], arr);
}