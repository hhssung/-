#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N, K;
	int visit[200001] = { 0 };
	queue<int> q;
	cin >> N >> K;
	q.push(N);

	int x, y;
	int tmp;

	visit[N] = 1;
	if (N != K)
	{
		while (!q.empty())
		{
			tmp = 0;
			x = q.front();
			q.pop();

			for (int i = 0; i < 3; i++)
			{
				switch (i)
				{
				case 0:
					y = x + 1;
					break;
				case 1:
					y = x - 1;
					break;
				case 2:
					y = x * 2;
					break;
				}

				if (y >= 0 && y <= 100000)
				{
					if (visit[y] == 0)
					{
						visit[y] = visit[x] + 1;
						if (y == K)
						{
							tmp = 1;
							break;
						}
						q.push(y);
					}
					
				}
			}
			if (tmp == 1)
			{
				break;
			}
		}
	}
	
	cout << visit[K] - 1 << endl;


	system("pause");
	return 0;
}


