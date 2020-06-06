#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> P;
int N, L, R;
int mov = 0;
int arr[50][50];
int printed[50][50];	//�ӽ÷� ����� �� �ٽ� arr�� ����.
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
		int val = arr[x][y]; //�⺻��
		int east = arr[x][y + 1];	//��
		int west = arr[x][y - 1];	//��
		int north = arr[x - 1][y];	//��
		int south = arr[x + 1][y];	//��
		if (y + 1 < N && check[x][y + 1] == 0)	//�� �湮 x
		{
			if (abs(east - val) >= L && abs(east - val) <= R)
			{
				pos.push(make_pair(x, y+1));
				spread(x, y + 1);
			}	//L���� ũ�� R���� ������ �� ��
		}
		if (y - 1 >= 0 && check[x][y - 1] == 0)	//��
		{
			if (abs(west - val) >= L && abs(west - val) <= R)
			{
				pos.push(make_pair(x, y-1));
				spread(x, y - 1);
			}	//L���� ũ�� R���� ������ �� ��
		}
		if (x + 1 < N&& check[x + 1][y] == 0)	//��
		{
			if (abs(south - val) >= L && abs(south - val) <= R)
			{
				pos.push(make_pair(x+1, y));
				spread(x + 1, y);
			}	//L���� ũ�� R���� ������ �� ��
		}
		if (x - 1 >= 0 && check[x - 1][y] == 0)	//��
		{
			if (abs(north - val) >= L && abs(north - val) <= R)
			{
				pos.push(make_pair(x-1, y));
				spread(x - 1, y);
			}	//L���� ũ�� R���� ������ �� ��
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
		}	//check �ʱ�ȭ,

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
					}	//�α��̵� �߻����� ���
					spreadsum = spreadsum / spreadv;

					P pp;
					while (!pos.empty())
					{
						pp=pos.front();
						printed[pp.first][pp.second] = spreadsum;
						pos.pop();

					}	//���� ���� ����ֱ�
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