#include <iostream>

using namespace std;

typedef struct rotate{
	int r;
	int c;
	int s;
}Rotate;

int N, M, K;
int arr[51][51];
int replarr[51][51];	//����� �迭
Rotate Rotatearr[6];	//ȸ�� ���� ���°�
int rotatecheck[6] = { 0 };	//���� �ߴ��� Ȯ��, ���� ����
int arrmin = 987654321;	//�迭���갪
int tempval[4][50];	//ȸ�����궧 �ʿ��� �ӽù迭

void cal()
{
	int count;
	for (int i = 1; i <= N; i++)
	{
		count = 0;
		for (int j = 1; j <= M; j++)
		{
			count += replarr[i][j];
		}
		//cout << count << endl;
		if (count < arrmin)
		{
			arrmin = count;
		}
	}

}

void rotating(int rotateval)
{
	int newr, newc, news;	
	newr=Rotatearr[rotateval].r;
	newc=Rotatearr[rotateval].c;
	news=Rotatearr[rotateval].s;
	for (int sval = 1; sval <= news; sval++) //1~s����
	{
		for (int i = 0; i < 2 * sval; i++)
		{
			tempval[0][i] = replarr[newr - sval][newc - sval + i];
			tempval[1][i] = replarr[newr - sval + i][newc + sval];
			tempval[2][i] = replarr[newr + sval][newc + sval - i];
			tempval[3][i] = replarr[newr + sval - i][newc - sval];	//�����ϱ�
		}

		for (int i = 0; i < 2 * sval; i++)
		{
			replarr[newr - sval][newc - sval + i + 1] = tempval[0][i];
			replarr[newr - sval + i + 1][newc + sval] = tempval[1][i];
			replarr[newr + sval][newc + sval - i - 1] = tempval[2][i];
			replarr[newr + sval - i - 1][newc - sval] = tempval[3][i];	//���̱�
		}
		// r-sval, c-sval ~ r-sval, c+sval-1   =>   r-sval, c-sval+1 ~ r-sval, c+sval : �� 2sval��
		// r-sval, c+sval ~ r+sval-1, c+sval =>   r-sval+1, c+sval ~ r+sval, c+sval
		// r+sval, c+sval ~ r+sval, c-sval+1  => r+sval, c+sval-1 ~ r+sval, c-sval
		// r+sval, c-sval ~ r-sval+1, c-sval => r+sval-1, c-sval ~ r-sval, c-sval	�ű��
	}
}

void DFS(int temp)
{
	if (temp < K)
	{
		for (int i = 0; i < K; i++)	//�迭 ã��
		{
			if (rotatecheck[i] == 0)
			{
				rotatecheck[i] = temp+1; //1~6 ����
				DFS(temp + 1);
				rotatecheck[i] = 0;
			}
		}
	}
	else {	//DFS ��
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				replarr[i][j] = arr[i][j];
			}
		}	//�迭 �����ϱ�
		for (int i = 1; i <= K; i++) //�������
		{
			for (int j = 0; j < K; j++)
			{
				if (rotatecheck[j] == i)	//1~K����
				{
					rotating(j);	//ȸ������ ����
				}
			}
		}
		cal();	//�迭 �� ����ؼ� ������Ʈ
	}
}

int main(void)
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}	//�迭 �ޱ�
	

	for (int i = 0; i < K; i++)	
	{
		cin >> Rotatearr[i].r >> Rotatearr[i].c >> Rotatearr[i].s;
	}	//ȸ�� ���� �ޱ�

	DFS(0);

	cout << arrmin;
	system("pause");
	return 0;
}