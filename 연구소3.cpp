#include <iostream>
#include <queue>


using namespace std;
typedef pair<int, int> P;

int time = 987654321;
int newtime;
int N, M; 
int k = 0;

queue <P> viruss;
int virus[10][3] = { 0 };

void search(int xpos, int ypos, int arr2[][50])
{
	int x = arr2[xpos][ypos];
	x++;
	if (xpos + 1 < N && arr2[xpos + 1][ypos] < 3 && arr2[xpos+1][ypos]!=1 )
	{
		if (arr2[xpos + 1][ypos] != 2)
		{
			newtime = x;
		}
		arr2[xpos + 1][ypos] = x;
		
		
		viruss.push(make_pair(xpos + 1, ypos));
	}
	if (ypos+1 < N && arr2[xpos][ypos+1] < 3 && arr2[xpos][ypos+1] != 1)
	{
		if (arr2[xpos][ypos+1] != 2)
		{
			newtime = x;
		}
		arr2[xpos][ypos+1] = x;
		viruss.push(make_pair(xpos, ypos+1));
	}
	if (xpos - 1 >=0 && arr2[xpos - 1][ypos] < 3 && arr2[xpos - 1][ypos] != 1)
	{
		if (arr2[xpos - 1][ypos] != 2)
		{
			newtime = x;
		}
		arr2[xpos - 1][ypos] = x;
		viruss.push(make_pair(xpos - 1, ypos));
	}
	if (ypos - 1 >=0 && arr2[xpos][ypos - 1] < 3 && arr2[xpos][ypos - 1] != 1)
	{
		if (arr2[xpos][ypos-1] != 2)
		{
			newtime = x;
		}
		arr2[xpos][ypos - 1] = x;
		viruss.push(make_pair(xpos, ypos - 1));
	}
}

void DFS(int temp, int t, int arr[][50]) {
	if (temp < M)
	{
		for (int i = t; i < k; i++)
		{
			if (arr[virus[i][0]][virus[i][1]] == 2)
			{
				arr[virus[i][0]][virus[i][1]] = 3;
				virus[i][2] = 1;
			}
			DFS(temp + 1, i+1, arr);
			arr[virus[i][0]][virus[i][1]] = 2;
			virus[i][2] = 0;
		}
	}
	else {
		int arr2[50][50];
		for (int i = 0; i < 10; i++)
		{
			if (virus[i][2] == 1)
			{
				viruss.push(make_pair(virus[i][0], virus[i][1]));
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr2[i][j] = arr[i][j];
			}
		}

		while (!viruss.empty())
		{
			P p = viruss.front();
			viruss.pop();
			search(p.first, p.second, arr2);
		}

		bool flag = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr2[i][j] == 0)
				{
					flag = 1;
					break;

				}

			}
			if (flag == 1)
			{
				break;
			}
		}

		if (newtime < time && flag==0)
		{
			time = newtime;
		}

	}
}


int main(void)
{
	iostream::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);

	int arr[50][50];

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 2)
			{
				virus[k][0] = i;
				virus[k][1] = j;
				k++;
			}
		}
	}

	DFS(0, 0, arr);


	if (time > 999999)
	{
		cout << "-1";
	}
	else if (time == 0)
	{
		cout << "0";
	}else{
		cout << time - 3;
	}

	system("pause");
	return 0;
}