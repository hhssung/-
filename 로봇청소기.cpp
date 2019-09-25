#include <iostream>

using namespace std;


int main(void)
{
	int N, M;
	// 0: 북 1: 동 2: 남 3: 서
	cin >> N >> M;
	int r, c; // 초기 청소기 위치
	int d;	//방향
	cin >> c >> r >> d;

	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {-1, 0, 1, 0};	//북, 동, 남, 서

	int arr[50][50];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	//2: 청소한 곳 1: 벽 0: 청소안함
	int clean = 0;
	int cases;	//cases 11: case a/b   cases 22: c/d
	bool flag = 1;
	while (1)
	{
		if (arr[c][r] == 0)
		{
			arr[c][r] = 2;
			clean++;
		}
		
		cases = 22;
		for (int i = 0; i < 4; i++)
		{
			if (arr[c + dy[i]][r + dx[i]] == 0)
			{
				cases = 11;
				break;
			}
		}

		if (cases == 22)
		{
			switch (d)
			{
			case 0:
				if (arr[c + dy[2]][r + dx[2]] == 1)	//남 벽일 경우
				{
					flag = 0;
				}
				else {
					c += dy[2];
					r += dx[2];	//한 칸 후진
				}
				break;
			case 1:
				if (arr[c + dy[3]][r + dx[3]] == 1)	//서 벽일 경우
				{
					flag = 0;
				}
				else {
					c += dy[3];
					r += dx[3];	//한 칸 후진
				}
				break;
			case 2:
				if (arr[c + dy[0]][r + dx[0]] == 1)	//북 벽일 경우
				{
					flag = 0;
				}
				else {
					c += dy[0];
					r += dx[0];	//한 칸 후진
				}
				break;
			case 3:
				if (arr[c + dy[1]][r + dx[1]] == 1)	//동 벽일 경우
				{
					flag = 0;
				}
				else {
					c += dy[1];
					r += dx[1];	//한 칸 후진
				}
				break;
			}
		}
		else {	//cases == 33
			switch (d)
			{
			case 0:
				if (arr[c + dy[3]][r + dx[3]] == 0)	//서 공간 존재
				{
					d = 3;
					c += dy[d];
					r += dx[d];
				}
				else {
					d = 3;
				}
				break;
			case 1:
				if (arr[c + dy[0]][r + dx[0]] == 0)	//북 공간 존재
				{
					d = 0;
					c += dy[d];
					r += dx[d];
				}
				else {
					d = 0;
				}
				break;
			case 2:
				if (arr[c + dy[1]][r + dx[1]] == 0)	//동 공간 존재
				{
					d = 1;
					c += dy[d];
					r += dx[d];
				}
				else {
					d = 1;
				}
				break;
			case 3:
				if (arr[c + dy[2]][r + dx[2]] == 0)	//서 공간 존재
				{
					d = 2;
					c += dy[d];
					r += dx[d];
				}
				else {
					d = 2;
				}
				break;
			}
		}

		

		if (flag == 0)
		{
			break;
		}

	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%3d", arr[i][j]);
		}
		cout << endl;
	}

	cout << clean;
	system("pause");
	return 0;
}