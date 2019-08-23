#include <iostream>
#include <queue>

using namespace std;

void BFS(int N, int dp[1000001], queue<int> q)
{
	
	int x, y;
	int flag;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		flag = 0;
		for (int i = 0; i < 3; i++)
		{
			y = -1;
			switch (i)
			{
			case 0:
				if (x % 3 == 0)
				{
					y = x / 3;
				}
				break;
			case 1:
				if (x % 2 == 0)
				{
					y = x / 2;
				}
				break;
			case 2:
				y = x - 1;
				break;
			}

			if (y > 1)
			{
				if (dp[y] == 0)
				{
					dp[y] = dp[x] + 1;
					q.push(y);
				}
			}
			else if (y == 1)
			{
				flag = 1;
				dp[y] = dp[x] + 1;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

int main(void)
{
	iostream::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);

	int N;
	queue <int> q;
	cin >> N;
	int dp[1000001] = { 0 };

	q.push(N);
	dp[N] = 1;

	BFS(N,dp,q);
	



	cout << dp[1] - 1 << endl;
	system("pause");
	return 0;
}