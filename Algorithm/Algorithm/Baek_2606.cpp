#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void solution_2606()
{
	vector<int> graph[100];
	int size,line;

	cin >> size;;
	cin >>line;

	for (int i = 0; i < line; i++)
	{
		int a,b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
	}

	queue<int> q;
	bool* visited = new bool[size];

	q.push(0);
	visited[0] = true;

	while (!q.empty()) { // ť�� �� ������ �ݺ�
	  // ť���� ��带 �ϳ� �� �´�. �� ��带 current��� ����.
		int current = q.front();
		q.pop();
		cout << current << endl;

		for (int next : graph[current]) { // current�� ���� ������ Ȯ���Ѵ�. �� ������ ��带 next��� ����.
			if (!visited[next]) { // ���� next�� �湮���� �ʾҴٸ�
				// next �湮
				q.push(next);
				visited[next] = true;
			}
		}

		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (visited[i])
			{
				count++;
				cout << i << endl;
			}
		}
	}
}
