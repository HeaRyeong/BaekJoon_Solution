#include <iostream>

using namespace std;
// N번째 큰수

int solution_2693()
{
	int T;
	int A[10];

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> A[j];

		// 정렬
		for (int k = 0; k < 9; k++)
		{
			for (int j = k + 1; j < 10; j++)
			{
				if (A[k] > A[j])
				{
					int temp = A[k];
					A[k] = A[j];
					A[j] = temp;
				}
			}
		}

		cout << A[7] << endl;
	}

	return 0;
}
