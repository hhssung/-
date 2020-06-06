#include <iostream>
using namespace std;
int chicdist = 987654321;
pair <int, int> chichome[13];

int dis(int xpo, int ypo, int M)
{
	int dist = 987654321;
	int temp;
	for (int i = 0; i < M; i++)
	{
		temp = abs(xpo - chichome[i].first) + abs(ypo - chichome[i].second);
		if (dist > temp)
		{
			dist = temp;
		}
	}
	return dist;
}

void DFS(int t, int xpos, int N, int M, int arr[][50])
{
	if (t < M)
	{
		for (int i = xpos; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 2)
				{
					arr[i][j] = 3;
					chichome[t].first = i;
					chichome[t].second = j;
					DFS(t + 1, i, N, M, arr);
					arr[i][j] = 2;
				}
			}
		}
	}
	else {
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 1)
				{
					sum += dis(i, j, M);
				}
			}
		}
		if (chicdist > sum)
		{
			chicdist = sum;
		}

	}
}

int main() {
	int N, M;
	cin >> N >> M;

	int arr[50][50];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	DFS(0, 0, N, M, arr);


	cout << chicdist << endl;

	return 0;
}