/*
���� 1�� : A
���� 2��: ABB �ּ� ���� 1+2
���� 3��: ABCBCC ABBCCCC �ּұ��� 1+2+3 (6) �ִ���� 1+2+4 (7)
���� 4��: ABCDBCCDDD ABBCCCCDDDDDDDD �ּұ��� 10 �ִ���� 15
11 ABCCD
12 ABCCCD ABBCD
13 ABBCCD
14 ABBCCCD

�ȵǴ� �� 2, 4, 5, 8,9

���� 5��: �ּ� 15 �ִ� 31
���� 6��: �ּ� 21 �ִ� 63
ABCDEF
...
ABBCCCDDDDDDDDD
���� 7�� : �ּ� 28 �ִ� 100
ABCDEFG
(���۰���)
A:1
B:2
C:3~4
D:4~8
E:5~16
F:6~32
G:7~64

*/


#include <iostream>

using namespace std;

int N;
int str[8] = { 0 };	// 1,2,3,4,5,6,7
int smax[7] = { 1,2,4,8,16,32,64 };
bool flag = 0;
char nstr[100] = { 0 };

void output(int snum)	//nstr (���ڿ�) �����
{
	for (int i = 0; i < snum; i++)
	{
		nstr[str[i+1]-1] = 'A' + i;
		str[i+1]--;
	}
	int temp=1;	//str[1]���� ���� 0 0 2 3
	for (int i = 0; i < N; i++)
	{
		if (nstr[i] == 0)
		{
			if (str[temp+1] != 0)	//greedy. ���� ���� ���ں��� ���ʴ�� ����
			{
				nstr[i] = 'A' + temp;
				str[temp+1]--;
			}
			else {
				temp++;
				nstr[i] = 'A' + temp;
				str[temp+1]--;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << nstr[i];
	}
}

void DFS(int count, int snum)
{
	if (count < snum && flag==0)	//DFS ����
	{
		for (int i = smax[count]; i >= str[count]+1; i--) //������ �ִ� ����~�� �� ����+1
		{
			str[count+1] = i;
			DFS(count + 1, snum);
			if (flag == 1)
			{
				break;
			}
		}
	}
	else {	//��ȿ�� �˻�
		int check = 0;
		for (int i = 0; i < snum; i++)
		{
			check += str[i+1];
		}
		if (check == N)
		{
			output(snum);
			flag = 1;
		}
	}
}

int main()
{
	int snum=1;	//�ʿ��� ���� ����
	cin >> N;
	
	if (N == 2 || N == 4 || N == 5 || N == 8 || N == 9)
	{
		cout << "-1";
	}
	else {
		int temp = N;
		while (temp != 1)
		{
			temp = temp / 2;
			snum++;
		}
		DFS(0,snum);
	}

	system("pause");
	return 0;
}