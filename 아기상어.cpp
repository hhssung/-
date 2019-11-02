#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> P;

int N;
int arr[20][20];
int bsharksize = 2;	//�Ʊ���ũ��
int bsharkeat = 0;	//���� ����� ����
int remainfish = 0;
int xpos;
int ypos;	//�Ʊ��� ��ġ
int dishtime = 0;	//����� ��Ƹ��� �� �ִ� �ð�

void BFS()
{
	int fishxpos = 21;	//���� �Ʒ���
	int fishypos = -1;	//���� ����	����� ��ǥ
	int fishval = 9;	//Ž�� ���̱� ���� ��ġ
	int newarr[20][20];
	queue <P> sharkpos;	//��� ��ġ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			newarr[i][j] = arr[i][j];
		}
	}
	sharkpos.push(make_pair(xpos, ypos));	//��� ��ġ push
	newarr[xpos][ypos] = 10;	//ù ��ġ���� 10���� ����
	while (!sharkpos.empty())	//BFS
	{
		P temp;
		temp = sharkpos.front();
		sharkpos.pop();
		int x = temp.first;
		int y = temp.second;

		if (fishval == newarr[x][y])	//Ž�� ��
		{
			break;
		}
		if (x-1>=0 && newarr[x-1][y]<=bsharksize)	//����
		{
			if (newarr[x - 1][y] == 0 || newarr[x - 1][y] == bsharksize)	//�� �Դ� ����⳪ �� ����
			{
				sharkpos.push(make_pair(x - 1, y));
				newarr[x - 1][y] = newarr[x][y] + 1;
			}
			else {	//���� �� �ִ� ���
				if (x - 1 < fishxpos) 	//���� �������� üũ
				{
					fishxpos = x - 1;
					fishypos = y;
					fishval = newarr[x][y] + 1;
					newarr[x - 1][y] = newarr[x][y] + 1;
				}
				else if (x - 1 == fishxpos)	//���� �Ȱ��� �� ���� ���� ���
				{
					if (y < fishypos)//�� ���ʿ� �ִ��� üũ
					{
						fishxpos = x - 1;
						fishypos = y;
						fishval = newarr[x][y] + 1;
						newarr[x - 1][y] = newarr[x][y] + 1;
					}
				}
			}
		}

		if (y - 1 >= 0 && newarr[x][y-1] <= bsharksize)	//����
		{
			if (newarr[x][y-1] == 0 || newarr[x][y-1] == bsharksize)	//���� ũ�� ����⳪ �� ����
			{
				sharkpos.push(make_pair(x, y-1));
				newarr[x][y-1] = newarr[x][y] + 1;
			}
			else {	//���� �� �ִ� ���
				if (x < fishxpos) 	//���� �������� üũ
				{
					fishxpos = x;
					fishypos = y-1;
					fishval = newarr[x][y] + 1;
					newarr[x][y - 1] = newarr[x][y] + 1;
				}
				else if (x == fishxpos)	//���� �Ȱ��� �� ���� ���� ���
				{
					if (y-1 < fishypos)//�� ���ʿ� �ִ��� üũ
					{
						fishxpos = x;
						fishypos = y-1;
						fishval = newarr[x][y] + 1;
						newarr[x][y - 1] = newarr[x][y] + 1;
					}
				}
			}
		}
		
		if (y + 1 < N && newarr[x][y + 1] <= bsharksize)	//������
		{
			if (newarr[x][y + 1] == 0 || newarr[x][y + 1] == bsharksize)	//���� ũ�� ����⳪ �� ����
			{
				sharkpos.push(make_pair(x, y + 1));
				newarr[x][y + 1] = newarr[x][y] + 1;
			}
			else {	//���� �� �ִ� ���
				if (x < fishxpos) 	//���� �������� üũ
				{
					fishxpos = x;
					fishypos = y + 1;
					fishval = newarr[x][y] + 1;
					newarr[x][y + 1] = newarr[x][y] + 1;
				}
				else if (x == fishxpos)	//���� �Ȱ��� �� ���� ���� ���
				{
					if (y + 1 < fishypos)//�� ���ʿ� �ִ��� üũ
					{
						fishxpos = x;
						fishypos = y + 1;
						fishval = newarr[x][y] + 1;
						newarr[x][y + 1] = newarr[x][y] + 1;
					}
				}
			}
		}

		if (x + 1 < N && newarr[x + 1][y] <= bsharksize)	//�Ʒ�
		{
			if (newarr[x + 1][y] == 0 || newarr[x + 1][y] == bsharksize)	//�� �Դ� ����⳪ �� ����
			{
				sharkpos.push(make_pair(x + 1, y));
				newarr[x + 1][y] = newarr[x][y] + 1;
			}
			else {	//���� �� �ִ� ���
				if (x + 1 < fishxpos) 	//���� �������� üũ
				{
					fishxpos = x + 1;
					fishypos = y;
					fishval = newarr[x][y] + 1;
					newarr[x + 1][y] = newarr[x][y] + 1;
				}
				else if (x + 1 == fishxpos)	//���� �Ȱ��� �� ���� ���� ���
				{
					if (y < fishypos)//�� ���ʿ� �ִ��� üũ
					{
						fishxpos = x + 1;
						fishypos = y;
						fishval = newarr[x][y] + 1;
						newarr[x + 1][y] = newarr[x][y] + 1;
					}
				}
			}
		}
		//while����
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
	
	if (fishxpos == 21)	// ���� �� �ִ� ����� ���� ��
	{
		remainfish = 0;
	}
	else {	//�Ծ��� ���
		arr[fishxpos][fishypos] = 0;	//����� ���� ��ġ 0����
		bsharkeat++;
		if (bsharkeat == bsharksize)	//��� ũ�� Ŀ��
		{
			bsharkeat = 0;
			bsharksize++;
		}
		xpos = fishxpos;
		ypos = fishypos;	//��� ��ġ ����
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
			if (arr[i][j] > 0)	//�����,��� ã��
			{
				remainfish++;
				if (arr[i][j] == 9)	//��� ��ġ ����
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