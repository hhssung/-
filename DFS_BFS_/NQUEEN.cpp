#include <iostream>

using namespace std;

int sum=0;

int dx[6] = { 1,-1,-1,1,1,-1 };
int dy[6] = { 1, -1, 1, -1,0,0};
bool arr2[15] = { 0 };

bool checkdiagonal(int xpos, int ypos, int N, bool arr[][15])
{
	bool T=0;
	int x;
	int y;

	for (int i = 0; i < 6; i++)
	{
		x = xpos;
		y = ypos;
		if (T == 1)
		{
			break;
		}
		while (1)
		{
			x += dx[i];
			y += dy[i];
			if (x < 0 || y < 0 || x >= N || y >= N)
			{
				break;
			}
			if (arr[x][y] == 1)
			{
				T = 1;
				break;
			}
		}
	}


	return T;
}



void DFS(int N, int count, bool arr[][15])
{
	if (count < N)
	{
		for (int i = 0; i < N; i++)
		{
			if (arr2[i] == 0)
			{
				if (checkdiagonal(count, i, N, arr) == 0)
				{
					arr[count][i] = 1;
					arr2[i] = 1;
					DFS(N, count + 1, arr);
					arr2[i] = 0;
					arr[count][i] = 0;
				}
			}
		}
	}
	else {
		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d ", arr[i][j]);
			}
			cout << endl;
		}*/
		sum++;
	}
}


int main(void)
{
	int N;
	cin >> N;
	bool arr[15][15] = { 0 };

	DFS(N, 0,arr);

	cout << sum;
	system("pause");
	return 0;
}