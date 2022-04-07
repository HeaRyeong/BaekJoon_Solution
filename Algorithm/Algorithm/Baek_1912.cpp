#include <iostream>
#include <vector>

using namespace std;

void solution_1912()
{
	int n;

	cin >> n;
	vector<int> v(n);
	vector<int> dp(n);

	int max;
	{
		int input;
		for (int i = 0; i < n; ++i)
		{
			cin >> input;
			v[i] = input;
		}
	}

	for (int i = 0; i < n; ++i)
	{

		if (i == 0)
		{
			dp[0] = v[0];
			max = dp[0];
		}
		else
		{
			if (dp[i - 1] + v[i] > v[i])
				dp[i] = dp[i - 1] + v[i];
			else
				dp[i] = v[i];

			if (max < dp[i])
				max = dp[i];
		}
	}

	cout << max << endl;

}