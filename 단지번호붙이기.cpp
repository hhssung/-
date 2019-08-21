#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
int N;
using namespace std;

void BFS(int arr[][27], int x, int y, int t, int &num)
{
	if (arr[x - 1][y] == 1)
	{
		num++;
		arr[x - 1][y] = t;
		BFS(arr, x - 1, y,t, num);
		
	}
	if (arr[x][y + 1] == 1)
	{
		num++;
		arr[x][y+1] = t;
		BFS(arr, x, y + 1, t,num);

	}
	if (arr[x + 1][y] == 1)
	{
		num++;
		arr[x + 1][y] = t;
		BFS(arr, x + 1, y, t, num);
	}
	if (arr[x][y - 1] == 1)
	{
		num++;
		arr[x][y-1] = t;
		BFS(arr, x, y - 1,t, num);
	}
}

int main(void)
{
	//int N;
	int arr[27][27] = { -1 };

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	
	int t=1;
	int num;
	vector <int> danji;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 1)
			{
				num = 1;
				t++;
				arr[i][j] = t;
				BFS(arr,i,j,t,num);
				danji.push_back(num);
			}
		}
	}
	

	sort(danji.begin(), danji.end());
	
	cout << t - 1 << endl;
	for (auto &x : danji)
	{
		cout << x << endl;
	}



	system("pause");
	return 0;
}