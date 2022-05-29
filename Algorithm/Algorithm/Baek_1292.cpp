#include <iostream>

using namespace std;
//쉽게 푸는 문제

int solution_1292()
{
	int num[1000];
	int check = 0;
	int input = 1;

	for (int i = 0; i < 1000; i++)
	{
		if (check < input)
		{

			num[i] = input;
			check++;
		}
		else
		{
			input++;
			check = 1;
			num[i] = input;
		}

	}

	int start, end;
	int sum = 0;

	cin >> start >> end;

	for (int i = start - 1; i < end; i++)
	{
		sum += num[i];
	}
	cout << sum << endl;


	return 0;
}
