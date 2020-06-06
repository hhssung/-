#include <iostream>

using namespace std;

int mmin = 987654321;
int N, M;
int arr[8][8];
int cnt = 0;	//cctv개수
int cctvtype[8];	//cctv 타입
int cctvxpos[8];
int cctvypos[8];	//cctv 좌표

/*
1번 : 11, 12, 13, 14
2번 : 21, 22
3번 : 31, 32, 33, 34
4번 : 41, 42, 43, 44
5번 : 51
*/

void down(int x, int y, int arr[][8])
{
	int dx = x + 1;
	int dy = y;
	while (dx < N)
	{
		if (arr[dx][dy] == 6) //벽일때
		{
			break;
		}
		if (arr[dx][dy] == 0)
		{
			arr[dx][dy] = -1;	//감시
		}
		dx = dx + 1;
	}
}

void left(int x, int y, int arr[][8])
{
	int dx = x;
	int dy = y - 1;
	while (dy >=0)
	{
		if (arr[dx][dy] == 6) //벽일때
		{
			break;
		}
		if (arr[dx][dy] == 0)
		{
			arr[dx][dy] = -1;	//감시
		}
		dy = dy - 1;
	}
}

void right(int x, int y, int arr[][8])
{
	int dx = x;
	int dy = y+1;
	while (dy <M)
	{
		if (arr[dx][dy] == 6) //벽일때
		{
			break;
		}
		if (arr[dx][dy] == 0)
		{
			arr[dx][dy] = -1;	//감시
		}
		dy = dy + 1;
	}
}

void up(int x, int y, int arr[][8])
{
	int dx = x-1;
	int dy = y;
	while (dx >= 0)
	{
		if (arr[dx][dy] == 6) //벽일때
		{
			break;
		}
		if (arr[dx][dy] == 0)
		{
			arr[dx][dy] = -1;	//감시
		}
		dx = dx - 1;
	}
}

void simulation()
{
	int newarr[8][8];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			newarr[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		int x = cctvxpos[i];
		int y = cctvypos[i];
		switch (newarr[x][y])
		{
		case 11:
			right(x, y, newarr);
			break;
		case 12:
			down(x, y, newarr);
			break;
		case 13:
			left(x, y, newarr);
			break;
		case 14:
			up(x, y, newarr);
			break;
		case 21:
			right(x, y, newarr);
			left(x, y, newarr);
			break;
		case 22:
			down(x, y, newarr);
			up(x, y, newarr);
			break;
		case 31:
			up(x, y, newarr);
			right(x, y, newarr);
			break;
		case 32:
			right(x, y, newarr);
			down(x, y, newarr);
			break;
		case 33:
			down(x, y, newarr);
			left(x, y, newarr);
			break;
		case 34:
			left(x, y, newarr);
			up(x, y, newarr);
			break;
		case 41:
			up(x, y, newarr);
			right(x, y, newarr);
			left(x, y, newarr);
			break;
		case 42:
			right(x, y, newarr);
			down(x, y, newarr);
			up(x, y, newarr);
			break;
		case 43:
			down(x, y, newarr);
			left(x, y, newarr);
			right(x, y, newarr);
			break;
		case 44:
			left(x, y, newarr);
			up(x, y, newarr);
			down(x, y, newarr);
			break;
		case 51:
			left(x, y, newarr);
			up(x, y, newarr);
			down(x, y, newarr);
			right(x, y, newarr);
			break;
		}
	}
	int c = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (newarr[i][j] == 0)
			{
				c++;
			}
		}
	}
	if (c < mmin)
	{
		mmin = c;
	}
}

void dfs(int flag)	//dfs
{
	if (flag < cnt)
	{
		int x = cctvxpos[flag];
		int y = cctvypos[flag];
		switch (cctvtype[flag])
		{
		case 1:
			for (int i = 11; i <= 14; i++)
			{
				arr[x][y] = i;
				dfs(flag + 1);
				arr[x][y] = 1;
			}
			break;
		case 2:
			for (int i = 21; i <= 22; i++)
			{
				arr[x][y] = i;
				dfs(flag + 1);
				arr[x][y] = 2;
			}
			break;
		case 3:
			for (int i = 31; i <= 34; i++)
			{
				arr[x][y] = i;
				dfs(flag + 1);
				arr[x][y] = 3;
			}
			break;
		case 4:
			for (int i = 41; i <= 44; i++)
			{
				arr[x][y] = i;
				dfs(flag + 1);
				arr[x][y] = 4;
			}
			break;
		case 5:
			arr[x][y] = 51;
			dfs(flag + 1);
			arr[x][y] = 5;
			break;
		}
	}
	else {
		simulation();
	}
}

int main(void)
{

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] > 0 && arr[i][j] < 6)	//cctv 발견
			{
				cctvtype[cnt] = arr[i][j];
				cctvxpos[cnt] = i;
				cctvypos[cnt] = j;
				cnt++;
			}	//cctv type, 위치, 개수 기록
		}
	}
	
	dfs(0);

	cout << mmin;
	system("pause");
	return 0;
}