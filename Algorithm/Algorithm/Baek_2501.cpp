#include <iostream>

using namespace std;
// 약수 구하기

int main()
{
	int N, K, solution, num;

	cin >> N >> K;
	solution = 0;

	for (int i = 1; i < N + 1; i++)
	{
		if (N % i == 0)
		{
			solution++;
			num = i;
		}
		if (K == solution)
			break;
	}
	if (solution < K)
		cout << "0" << endl;
	else
		cout << num << endl;

	return 0;
}
