#include <iostream>

using namespace std;


int Bubble()
{
	int a[5] = { 7,4,11,9,2 };

	cout << "������" << endl;

	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - (i+1); j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	cout <<endl << "������" << endl;

	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";

	return 0;
}