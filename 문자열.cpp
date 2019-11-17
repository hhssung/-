/*
문자 1개 : A
문자 2개: ABB 최소 길이 1+2
문자 3개: ABCBCC ABBCCCC 최소길이 1+2+3 (6) 최대길이 1+2+4 (7)
문자 4개: ABCDBCCDDD ABBCCCCDDDDDDDD 최소길이 10 최대길이 15
11 ABCCD
12 ABCCCD ABBCD
13 ABBCCD
14 ABBCCCD

안되는 것 2, 4, 5, 8,9

문자 5개: 최소 15 최대 31
문자 6개: 최소 21 최대 63
ABCDEF
...
ABBCCCDDDDDDDDD
문자 7개 : 최소 28 최대 100
ABCDEFG
(시작가능)
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

void output(int snum)	//nstr (문자열) 만들기
{
	for (int i = 0; i < snum; i++)
	{
		nstr[str[i+1]-1] = 'A' + i;
		str[i+1]--;
	}
	int temp=1;	//str[1]부터 시작 0 0 2 3
	for (int i = 0; i < N; i++)
	{
		if (nstr[i] == 0)
		{
			if (str[temp+1] != 0)	//greedy. 제일 빠른 문자부터 차례대로 넣음
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
	if (count < snum && flag==0)	//DFS 실행
	{
		for (int i = smax[count]; i >= str[count]+1; i--) //범위는 최대 범위~그 전 범위+1
		{
			str[count+1] = i;
			DFS(count + 1, snum);
			if (flag == 1)
			{
				break;
			}
		}
	}
	else {	//유효성 검사
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
	int snum=1;	//필요한 문자 개수
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