#include <iostream>

using namespace std;

int N;
int arr[21][21];
int minimum = 987654321;


void maked1d2(int x, int y, int d1, int d2)
{
	int city[6] = { 0 };	//선거구 1,2,3,4,5
	int divide[21][21] = { 0 };	//선거구 번호 나누기
	for (int i=0; i<=d1; i++)
	{
		for (int j=0; j<=d2; j++)
		{
			divide[x+j+i][y+j-i] = 5;
			city[5] += arr[x + j + i][y + j - i];	//큰 대각사각형 선거구 5에 미리 더해놓기
		}
	}
	for (int i = 0; i <= d1-1; i++)
	{
		for (int j = 0; j <= d2-1; j++)
		{
			divide[x +1+ j + i][y + j - i] = 5;
			city[5] += arr[x + 1 + j + i][y + j - i];	//작은 대각사각형 선거구 5에 미리 더해놓기
		}
	}

	for (int i = 1; i <= x + d1-1; i++)	//선거구 1
	{
		for (int j = 1; j <= y; j++)
		{
			if (divide[i][j] != 5)
			{
				//divide[i][j] = 1;
				city[1] += arr[i][j];
			}
		}
	}
	for (int i = 1; i <= x + d2; i++)	//선거구 2
	{
		for (int j = y+1; j <= N; j++)
		{
			if (divide[i][j] != 5)
			{
				//divide[i][j] = 2;
				city[2] += arr[i][j];
			}
		}
	}
	for (int i = x+d1; i <= N; i++)	//선거구 3
	{
		for (int j = 1; j <= y-d1+d2-1; j++)
		{
			if (divide[i][j] != 5)
			{
				//divide[i][j] = 3;
				city[3] += arr[i][j];
			}
		}
	}
	for (int i = x+d2+1; i <= N; i++)	//선거구 4
	{
		for (int j = y-d1+d2; j <= N; j++)
		{
			if (divide[i][j] != 5)
			{
				//divide[i][j] = 4;
				city[4] += arr[i][j];
			}
		}
	}

	int maxval = 0;
	int minval = 987654321;
	for (int i = 1; i < 6; i++)
	{
		if (maxval < city[i])
		{
			maxval = city[i];
		}
		if (minval > city[i])
		{
			minval = city[i];
		}
	}
	if (maxval - minval < minimum)
	{
		minimum = maxval - minval;
		/*
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << divide[i][j];
			}
			cout << endl;
		}
		cout << endl;
		*/
	}
}

void makeval()	//x,y,d1,d2 만들기
{
	for (int x = 1; x <= N-2; x++)	
	{
		for (int y = 2; y <= N - 1; y++) //x,y 정하기
		{
			for (int d1 = 1; d1 <= y - 1; d1++)
			{
				for (int d2 = 1; d2 <= N - y; d2++)	//d1,d2 정하기
				{
					if (d1 + d2 <= N - x)	//맨 밑 위치 만족시
					{
						maked1d2(x,y,d1,d2);	//모든 조건 만족, 계산 시작
					}
				}
			}
		}
	}
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)	//x
	{
		for (int j = 1; j <= N; j++)	//y
		{
			cin >> arr[i][j];
		}
	}
	
	makeval();
	cout << minimum;

	system("pause");
	return 0;
}