#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> P;

int N;
int arr[20][20];
int bsharksize = 2;	//아기상어크기
int bsharkeat = 0;	//먹은 물고기 개수
int remainfish = 0;
int xpos;
int ypos;	//아기상어 위치
int dishtime = 0;	//물고기 잡아먹을 수 있는 시간

void BFS()
{
	int fishxpos = 21;	//가장 아래쪽
	int fishypos = -1;	//가장 왼쪽	물고기 좌표
	int fishval = 9;	//탐색 줄이기 위한 장치
	int newarr[20][20];
	queue <P> sharkpos;	//상어 위치
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			newarr[i][j] = arr[i][j];
		}
	}
	sharkpos.push(make_pair(xpos, ypos));	//상어 위치 push
	newarr[xpos][ypos] = 10;	//첫 위치에서 10으로 시작
	while (!sharkpos.empty())	//BFS
	{
		P temp;
		temp = sharkpos.front();
		sharkpos.pop();
		int x = temp.first;
		int y = temp.second;

		if (fishval == newarr[x][y])	//탐색 끝
		{
			break;
		}
		if (x-1>=0 && newarr[x-1][y]<=bsharksize)	//위로
		{
			if (newarr[x - 1][y] == 0 || newarr[x - 1][y] == bsharksize)	//못 먹는 물고기나 빈 공간
			{
				sharkpos.push(make_pair(x - 1, y));
				newarr[x - 1][y] = newarr[x][y] + 1;
			}
			else {	//먹을 수 있는 고기
				if (x - 1 < fishxpos) 	//가장 위쪽인지 체크
				{
					fishxpos = x - 1;
					fishypos = y;
					fishval = newarr[x][y] + 1;
					newarr[x - 1][y] = newarr[x][y] + 1;
				}
				else if (x - 1 == fishxpos)	//만약 똑같이 맨 위에 있을 경우
				{
					if (y < fishypos)//더 왼쪽에 있는지 체크
					{
						fishxpos = x - 1;
						fishypos = y;
						fishval = newarr[x][y] + 1;
						newarr[x - 1][y] = newarr[x][y] + 1;
					}
				}
			}
		}

		if (y - 1 >= 0 && newarr[x][y-1] <= bsharksize)	//왼쪽
		{
			if (newarr[x][y-1] == 0 || newarr[x][y-1] == bsharksize)	//같은 크기 물고기나 빈 공간
			{
				sharkpos.push(make_pair(x, y-1));
				newarr[x][y-1] = newarr[x][y] + 1;
			}
			else {	//먹을 수 있는 고기
				if (x < fishxpos) 	//가장 위쪽인지 체크
				{
					fishxpos = x;
					fishypos = y-1;
					fishval = newarr[x][y] + 1;
					newarr[x][y - 1] = newarr[x][y] + 1;
				}
				else if (x == fishxpos)	//만약 똑같이 맨 위에 있을 경우
				{
					if (y-1 < fishypos)//더 왼쪽에 있는지 체크
					{
						fishxpos = x;
						fishypos = y-1;
						fishval = newarr[x][y] + 1;
						newarr[x][y - 1] = newarr[x][y] + 1;
					}
				}
			}
		}
		
		if (y + 1 < N && newarr[x][y + 1] <= bsharksize)	//오른쪽
		{
			if (newarr[x][y + 1] == 0 || newarr[x][y + 1] == bsharksize)	//같은 크기 물고기나 빈 공간
			{
				sharkpos.push(make_pair(x, y + 1));
				newarr[x][y + 1] = newarr[x][y] + 1;
			}
			else {	//먹을 수 있는 고기
				if (x < fishxpos) 	//가장 위쪽인지 체크
				{
					fishxpos = x;
					fishypos = y + 1;
					fishval = newarr[x][y] + 1;
					newarr[x][y + 1] = newarr[x][y] + 1;
				}
				else if (x == fishxpos)	//만약 똑같이 맨 위에 있을 경우
				{
					if (y + 1 < fishypos)//더 왼쪽에 있는지 체크
					{
						fishxpos = x;
						fishypos = y + 1;
						fishval = newarr[x][y] + 1;
						newarr[x][y + 1] = newarr[x][y] + 1;
					}
				}
			}
		}

		if (x + 1 < N && newarr[x + 1][y] <= bsharksize)	//아래
		{
			if (newarr[x + 1][y] == 0 || newarr[x + 1][y] == bsharksize)	//못 먹는 물고기나 빈 공간
			{
				sharkpos.push(make_pair(x + 1, y));
				newarr[x + 1][y] = newarr[x][y] + 1;
			}
			else {	//먹을 수 있는 고기
				if (x + 1 < fishxpos) 	//가장 위쪽인지 체크
				{
					fishxpos = x + 1;
					fishypos = y;
					fishval = newarr[x][y] + 1;
					newarr[x + 1][y] = newarr[x][y] + 1;
				}
				else if (x + 1 == fishxpos)	//만약 똑같이 맨 위에 있을 경우
				{
					if (y < fishypos)//더 왼쪽에 있는지 체크
					{
						fishxpos = x + 1;
						fishypos = y;
						fishval = newarr[x][y] + 1;
						newarr[x + 1][y] = newarr[x][y] + 1;
					}
				}
			}
		}
		//while문끝
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << newarr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	if (fishxpos == 21)	// 먹을 수 있는 물고기 없을 때
	{
		remainfish = 0;
	}
	else {	//먹었을 경우
		arr[fishxpos][fishypos] = 0;	//물고기 먹은 위치 0으로
		bsharkeat++;
		if (bsharkeat == bsharksize)	//상어 크기 커짐
		{
			bsharkeat = 0;
			bsharksize++;
		}
		xpos = fishxpos;
		ypos = fishypos;	//상어 위치 변경
		dishtime = dishtime + newarr[fishxpos][fishypos] - 10;
		remainfish--;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] > 0)	//물고기,상어 찾기
			{
				remainfish++;
				if (arr[i][j] == 9)	//상어 위치 저장
				{
					remainfish--;
					xpos = i;
					ypos = j;
					arr[i][j] = 0;
				}
			}
		}
	}
	while (remainfish > 0)
	{
		BFS();
	}

	cout << dishtime;

	system("pause");
	return 0;
}