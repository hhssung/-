#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> P;

int main(void)
{
	int N, K;
	int arr[101][101] = { -1 };	//-1: ��  0: �� ����  1: ���  2: ��
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = 0;	//�� ĭ �ʱ�ȭ
		}
	}
	cin >> K;
	int x, y;
	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		arr[x][y] = 1;	//��� �Է�
	}

	int L;
	cin >> L;
	char info[10001];
	for (int i = 1; i <= 10000; i++)
	{
		info[i] = 'X';	//�ð�, ��ȯ���� �ʱ�ȭ
	}
	int aaa;
	char bbb;
	for (int i = 0; i < L; i++)
	{
		cin >> aaa >> bbb;
		info[aaa+1] = bbb;
	}

	queue <P> pos;	// ���� ��ġ ����
	P head;
	head.first = 1;
	head.second = 1;	//���� �Ӹ� ��ǥ (x,y)
	pos.push(make_pair(1, 1));	// ��ǥ 1,1 push

	int time = 0;
	int rotate = 1;	//1: ������ 2: �Ʒ� 3: ���� 4: ����
	while (1)
	{
		time++;
		switch (info[time])
		{
		case 'L':
			switch (rotate)
			{
			case 1:
				rotate = 4;
				break;
			case 2:
				rotate = 1;
				break;
			case 3:
				rotate = 2;
				break;
			case 4:
				rotate = 3;
				break;
			}
			break;
		case 'D':
			switch (rotate)
			{
			case 1:
				rotate = 2;
				break;
			case 2:
				rotate = 3;
				break;
			case 3:
				rotate = 4;
				break;
			case 4:
				rotate = 1;
				break;
			}
			break;
		default:
			break;
		}		// ��ġ�� �ٲٴ��� ����

		switch (rotate)
		{
		case 1:	//������
			head.first++;
			break;
		case 2:	//�Ʒ�
			head.second++;
			break;
		case 3:	//����
			head.first--;
			break;
		case 4:	//��
			head.second--;
			break;
		}

		bool flag = 1;
		P tt;
		if (head.first < 1 || head.second < 1 || head.first >N || head.second > N)
		{
			flag = 0;
		}
		else {
			switch (arr[head.second][head.first])
			{
			case 0:
				pos.push(make_pair(head.first, head.second));
				arr[head.second][head.first] = 2;
				tt = pos.front();
				arr[tt.second][tt.first] = 0;
				pos.pop();
				break;	//�� ĭ
			case 1:
				pos.push(make_pair(head.first, head.second));
				arr[head.second][head.first] = 2;
				break;	//���
			default:
				flag = 0;
				break;	// ���̰ų� ����� ���
			}
		}

		if (flag == 0)
		{
			break;
		}
		/*
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}
		system("pause");

		*/
	}

	cout << time;

	system("pause");
	return 0;
}