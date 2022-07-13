#include <iostream>
using namespace std;

class Baek_14500
{
public:
	Baek_14500()
	{
		solution_14500();
	}
	void solution_14500()
	{	
		cin >> N >> M;

		init_paper();

		// pos�� �����̸鼭 ó������ ������ �ѹ� ��ĵ���Ѵ�!
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				// ���� ��Ʈ�ι̳� �ϳ��� ���� �� �ִ��� üũ
				
				// 1) (4,1)
				if (i + 3 < N)
				{
					int temp = 0;
					for (int h = 0; h < 4; ++h)
						temp += paper[i + h][j];

					if (temp > max)
						max = temp;

				}
				//  1���� ���
				// 2) (1,4)
				if (j + 3 < M)
				{
					int temp = 0;
					for (int h = 0; h < 4; ++h)
						temp += paper[i][j + h];

					if (temp > max)
						max = temp;

				}
				//  1���� ���
				// 3) (2,2)
				if (i + 1 < N && j + 1 < M)
				{
					int temp = 0;
					for (int k = 0; k < 2; ++k)
					{
						for (int h = 0; h < 2; ++h)
							temp += paper[i + k][j + h];
					}
					if (temp > max)
						max = temp;
				}
				//  1���� ���
				// 4) (3,2)
				if (i + 2 < N && j + 1 < M)
				{
					{
						int temp = 0;
						temp += paper[i][j];
						temp += paper[i + 1][j];
						temp += paper[i + 2][j];
						temp += paper[i + 2][j + 1];
						if (temp > max)
							max = temp;
					}

					{
						int temp = 0;
						temp += paper[i][j];
						temp += paper[i][j + 1];
						temp += paper[i + 1][j + 1];
						temp += paper[i + 2][j + 1];
						if (temp > max)
							max = temp;
					}

					{
						int temp = 0;
						temp += paper[i][j];
						temp += paper[i + 1][j];
						temp += paper[i + 1][j + 1];
						temp += paper[i + 2][j + 1];
						if (temp > max)
							max = temp;
					}

					{
						int temp = 0;
						temp += paper[i][j];
						temp += paper[i + 1][j];
						temp += paper[i + 1][j + 1];
						temp += paper[i + 2][j];
						if (temp > max)
							max = temp;
					}

					{
						int temp = 0;
						temp += paper[i][j + 1];
						temp += paper[i + 1][j];
						temp += paper[i + 1][j + 1];
						temp += paper[i + 2][j + 1];
						if (temp > max)
							max = temp;
					}
				}
				//  5���� ���
				// 5) (2,3)
				if (i + 1 < N && j + 2 < M)
				{
					{
						int temp = 0;
						temp += paper[i][j];
						temp += paper[i + 1][j];
						temp += paper[i][j + 1];
						temp += paper[i][j + 2];
						if (temp > max)
							max = temp;
					}

					{
						int temp = 0;
						temp += paper[i + 1][j];
						temp += paper[i + 1][j + 1];
						temp += paper[i + 1][j + 2];
						temp += paper[i][j + 2];
						if (temp > max)
							max = temp;
					}

					{
						int temp = 0;
						temp += paper[i + 1][j];
						temp += paper[i][j + 1];
						temp += paper[i][j + 2];
						temp += paper[i + 1][j + 1];
						if (temp > max)
							max = temp;
					}

					{
						int temp = 0;
						temp += paper[i + 1][j];
						temp += paper[i][j + 1];
						temp += paper[i + 1][j + 1];
						temp += paper[i + 1][j + 2];
						if (temp > max)
							max = temp;
					}

					{
						int temp = 0;
						temp += paper[i][j];
						temp += paper[i][j + 1];
						temp += paper[i][j + 2];
						temp += paper[i + 1][j + 1];
						if (temp > max)
							max = temp;
					}
				}
				//  5���� ���
			}
		}	

		cout << max << endl;
	}

	void init_paper()
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
				cin >> paper[i][j];
		}
	}

	void print_paper()
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
				cout << paper[i][j] <<" ";
			cout << endl;
		}
	}

public:
	int N;
	int M;
	int paper[500][500];
	int max = 0;
};