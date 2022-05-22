#include <iostream>

using namespace std;
// 지능형 기차 2

int solution_2460()
{
	int data[10][2];
	int max = 0;
	int headcount = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> data[i][0] >> data[i][1];
	}

	for (int i = 0; i < 10; i++)
	{
		headcount -= data[i][0];
		headcount += data[i][1];
		if (max < headcount)
			max = headcount;
	}

	cout << max;

	return 0;
}