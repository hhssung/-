#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> P;
int N, L, R;
int mov = 0;
int arr[50][50];
int printed[50][50];	//임시로 기록한 후 다시 arr에 복사.
bool check[50][50];
queue <P> pos;


int spreadv;
int spreadsum;
void spread(int x, int y)
{
	if (check[x][y] == 0)
	{
		//pos.push(make_pair(x,y));
		check[x][y] = 1;
		spreadsum += arr[x][y];
		spreadv++;
		int val = arr[x][y]; //기본값
		int east = arr[x][y + 1];	//동
		int west = arr[x][y - 1];	//서
		int north = arr[x - 1][y];	//북
		int south = arr[x + 1][y];	//남
		if (y + 1 < N && check[x][y + 1] == 0)	//동 방문 x
		{
			if (abs(east - val) >= L && abs(east - val) <= R)
			{
				pos.push(make_pair(x, y+1));
				spread(x, y + 1);
			}	//L보다 크고 R보다 작은지 값 비교
		}
		if (y - 1 >= 0 && check[x][y - 1] == 0)	//서
		{
			if (abs(west - val) >= L && abs(west - val) <= R)
			{
				pos.push(make_pair(x, y-1));
				spread(x, y - 1);
			}	//L보다 크고 R보다 작은지 값 비교
		}
		if (x + 1 < N&& check[x + 1][y] == 0)	//남
		{
			if (abs(south - val) >= L && abs(south - val) <= R)
			{
				pos.push(make_pair(x+1, y));
				spread(x + 1, y);
			}	//L보다 크고 R보다 작은지 값 비교
		}
		if (x - 1 >= 0 && check[x - 1][y] == 0)	//북
		{
			if (abs(north - val) >= L && abs(north - val) <= R)
			{
				pos.push(make_pair(x-1, y));
				spread(x - 1, y);
			}	//L보다 크고 R보다 작은지 값 비교
		}
	}
}

int main(void)
{
	

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			
		}
	}

	bool flag=1;
	while (flag == 1)
	{
		flag = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				check[i][j] = 0;
			}
		}	//check 초기화,

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (check[i][j] == 0)
				{
					spreadsum = 0;
					spreadv = 0;
					pos.push(make_pair(i, j));
					spread(i,j);
					if (spreadv >= 2)
					{
						flag = 1;
					}	//인구이동 발생했을 경우
					spreadsum = spreadsum / spreadv;

					P pp;
					while (!pos.empty())
					{
						pp=pos.front();
						printed[pp.first][pp.second] = spreadsum;
						pos.pop();

					}	//나눈 값들 집어넣기
				}
				

			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = printed[i][j];
				//printf_s("%3d", printed[i][j]);
			}
			//cout << endl;
		}

		if (flag == 1)
		{
			mov++;
		}
		}


	cout << mov;
	system("pause");
	return 0;
}