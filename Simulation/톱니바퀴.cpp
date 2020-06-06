#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int clocks[4][8];

void clock(int num)
{
	int k = clocks[num][7];
	for (int i = 6; i >= 0; i--)
	{
		clocks[num][i + 1] = clocks[num][i];
	}
	clocks[num][0] = k;
}

void cntclock(int num)
{
	int k = clocks[num][0];
	for (int i = 0; i < 7; i++)
	{
		clocks[num][i] = clocks[num][i + 1];
	}
	clocks[num][7] = k;
}


int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &clocks[i][j]);
		}
	}
	int K;
	cin >> K;
	int clocknum, spin;

	int temp;
	int newspin;
	int arr[4];

	for (int i = 0; i < K; i++)
	{
		cin >> clocknum >> spin;
		clocknum--;

		for (int j = 0; j < 4; j++)
		{
			arr[j] = 0;
		}
		arr[clocknum] = spin;

		newspin = spin;
		temp = clocknum + 1;
		while (temp <= 3)	// 기준 오른쪽. 2-6
		{
			if (clocks[temp - 1][2] == clocks[temp][6])
			{
				break;
			}
			else {
				newspin = newspin * (-1);
				if (newspin == 1)
				{
					arr[temp] = 1;
				}
				else {
					arr[temp] = -1;
				}
			}
			temp++;
		}
		newspin = spin;
		temp = clocknum - 1;
		while (temp >= 0)	// 기준 왼쪽. 6-2
		{
			if (clocks[temp + 1][6] == clocks[temp][2])
			{
				break;
			}
			else {
				newspin = newspin * (-1);
				if (newspin == 1)
				{
					arr[temp] = 1;
				}
				else {
					arr[temp] = -1;
				}
			}
			temp--;
		}

		for (int j = 0; j < 4; j++)
		{
			if (arr[j] == 1)
			{
				clock(j);
			}
			else if (arr[j] == -1)
			{
				cntclock(j);
			}
		}

	}

	cout << clocks[0][0] + clocks[1][0] * 2 + clocks[2][0] * 4 + clocks[3][0] * 8;

	//system("pause");
	return 0;
}