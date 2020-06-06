#include <iostream>

using namespace std;
typedef pair<int, int> P;



int main(void)
{
	int N;
	int x, y, d, g;
	bool check[101][101] = { 0 }; // arr[0][0]= (0,0)  
	P arr[1025];  // x, y

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> d >> g;
		//check[y][x] = 1;
		arr[0].first = x;
		arr[0].second = y;
		switch (d)
		{
		case 0:
			arr[1].first = x + 1;
			arr[1].second = y;
			//check[y][x + 1] = 1;
			break;
		case 1:
			arr[1].first = x;
			arr[1].second = y-1;
			//check[x][y - 1] = 1;
			break;
		case 2:
			arr[1].first = x - 1;
			arr[1].second = y;
			//check[x - 1][y] = 1;
			break;
		case 3:
			arr[1].first = x;
			arr[1].second = y+1;
			//check[x][y + 1] = 1;
			break;
		}
		int t = 1;
		int aa, bb, cc, dd;
		for (int j = 0; j < g; j++)	//세대
		{
			//arr[t].first, arr[t].second -> 중심점 (a,b)
			//arr[t-k].first, arr[t-k].second -> 끝점 (c,d)
			//arr[t+k].first, arr[t+k].second -> 목표점
			for (int k = 1; k <= t; k++)
			{
				aa = arr[t].first;
				bb = arr[t].second;
				cc = arr[t - k].first;
				dd = arr[t - k].second;
				arr[t + k].first = bb - dd + aa;
				arr[t + k].second = cc - aa + bb;
			}
			t *= 2;
		}
		for (int j = 0; j <= t; j++)
		{
			if(arr[j].first>=0 && arr[j].second>=0 && arr[j].first<=100 && arr[j].second<=100)
			check[arr[j].second][arr[j].first] = 1;
		}
		/*
		for (int j = 0; j <= 10; j++)
		{
			for (int k = 0; k <= 10; k++)
			{
				cout << check[j][k];
			}
			cout << endl;
		}
		*/
	}

	int sum=0;
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (check[i][j] == 1 && check[i + 1][j] == 1 && check[i][j + 1] == 1 && check[i + 1][j + 1] == 1)
			{
				sum++;
			}
		}
	}

	cout << sum;

	system("pause");
	return 0;
}
/*
중심점 (a,b)
끝 점 (c,d)일 때
90도 회전시 (b-d+a, c-a+b)


*/