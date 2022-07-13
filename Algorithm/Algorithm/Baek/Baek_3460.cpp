#include <iostream>

using namespace std;
// ÀÌÁø¼ö

int solution_3460()
{
	int T, n;

	cin >> T;

	
	for (int i = 0; i < T; i++)
	{
		cin >> n;

		for (int j = 0;; j++)
		{
			if (n % 2 == 1)
				cout << j << " ";
			n = n / 2;

			if (n / 2 == 0 && n % 2 == 0)
				break;
		}
	}

	return 0;
}