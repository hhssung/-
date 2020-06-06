#include <iostream>
#include <cmath>

using namespace std;

int s=999999;
int team1[10];
int team2[10];
int team1sum;
int team2sum;

void DFS(int temp, int g, int num, int arr[][20])
{
	if (temp < num)	//¿ÏÀüÅ½»öÁß
	{
		for (int i = g; i < 2*num; i++)
		{
			team1[temp] = i;
			DFS(temp + 1, i+1, num, arr);
			team1[temp] = 0;
		}
	}
	else {	//Å½»ö ³¡
		int n=0;
		int k;
		for (int i = 0; i < 2 * num; i++)
		{
			k = 0;
			for (int j = 0; j < num; j++)
			{
				if (team1[j] == i)
				{
					k = 1;
					break;
				}
			}
			if(k==0)
			{
				team2[n] = i;
				n++;
			}
		}
		team1sum = 0;
		team2sum = 0;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				team1sum += arr[team1[i]][team1[j]];
				team2sum += arr[team2[i]][team2[j]];
			}
		}
		if (s > abs(team1sum - team2sum))
		{
			s = abs(team1sum - team2sum);
		}



	}

}


int main(void)
{
	int arr[20][20];
	int N;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	DFS(0, 0, N/2, arr);
	


	cout << s;


	system("pause");
	return 0;
}