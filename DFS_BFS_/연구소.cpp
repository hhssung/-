#include <iostream>

using namespace std;

int N, M;
int safetyzone = 0;

void BFS(int xpos, int ypos, int arr2[][8])
{
	if (xpos+1<N && arr2[xpos + 1][ypos] == 0)
	{
		arr2[xpos + 1][ypos] = 3;
		BFS(xpos + 1, ypos, arr2);
	}
	if (ypos+1<M && arr2[xpos][ypos + 1] == 0)
	{
		arr2[xpos][ypos+1] = 3;
		BFS(xpos, ypos+1, arr2);
	}
	if (xpos-1>=0 && arr2[xpos - 1][ypos] == 0)
	{
		arr2[xpos -1][ypos] = 3;
		BFS(xpos - 1, ypos, arr2);
	}
	if (ypos-1 >= 0 && arr2[xpos][ypos - 1] == 0)
	{
		arr2[xpos][ypos-1] = 3;
		BFS(xpos, ypos-1, arr2);
	}

}

void DFS(int temp, int xpo, int arr[][8])
{
	if (temp < 3)
	{
		for (int i = xpo; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] == 0)
				{
					arr[i][j] = 1;
					DFS(temp + 1, i, arr);
					arr[i][j] = 0;
				}
			}
		}
	}else {
		int k=0;
		int arr2[8][8];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				arr2[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr2[i][j] == 2)
				{
					BFS(i, j, arr2);
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr2[i][j] == 0)
				{
					k++;
				}
			}
		}

		if (safetyzone < k)
		{
			safetyzone = k;
		}
	}
}

int main(void)
{
	cin >> N >> M;
	int arr[8][8];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	DFS(0, 0, arr);

	cout << safetyzone << endl;
	system("pause");
	return 0;
}