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

	while (!q.empty()) { // 큐가 빌 때까지 반복
	  // 큐에서 노드를 하나 빼 온다. 이 노드를 current라고 하자.
		int current = q.front();
		q.pop();
		cout << current << endl;

		for (int next : graph[current]) { // current의 인접 노드들을 확인한다. 이 각각의 노드를 next라고 하자.
			if (!visited[next]) { // 만일 next에 방문하지 않았다면
				// next 방문
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
