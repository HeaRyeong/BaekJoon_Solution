#include <iostream>

using namespace std;
// 최대공약수와 최소공배수

int solution_2609()
{
	int A, B, a, b, GCD = 1, LCM = 1;
	int divisor = 2;
	cin >> A >> B;
	a = A;
	b = B;
	while (true)
	{

		if (a % divisor == 0 && b % divisor == 0)
		{
			GCD *= divisor;
			LCM *= divisor;
			a = a / divisor;
			b = b / divisor;

		}
		else
		{
			if (divisor > A || divisor > B)
				break;
			else
				divisor++;
		}
	}
	LCM *= a * b;

	cout << GCD << " " << LCM << endl;

	return 0;
}
