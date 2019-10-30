#include <iostream>

using namespace std;

int N;
int A[100];
int Aop[99];
int op[4]; // +는 0, -는 1, *는 2, /는 3
int maax = -1000000000;	//-10억
int miin = 1000000000;	//10억


void calc()
{
	int val = A[0];
	for (int i = 0; i < N - 1; i++)
	{
		switch (Aop[i])
		{
		case 0:		// +
			val = val + A[i + 1];
			break;
		case 1:		// -
			val = val - A[i + 1];
			break;
		case 2:		// *
			val = val * A[i + 1];
			break;
		case 3:		// 나누기
			val = val / A[i + 1];
			break;
		}
	}
	//cout << val;
	if (maax < val)
	{
		maax = val;
	}
	if (miin > val)
	{
		miin = val;
	}
}

void dfs(int flag)
{
	if (flag < N-1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (op[i] != 0)
			{
				Aop[flag] = i;
				op[i]--;
				dfs(flag + 1);
				op[i]++;
			}
		}
	}
	else {	//dfs 종료
		calc();
	}
}

int main()
{
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}
	dfs(0);
	
	cout << maax << endl;
	cout << miin;
	system("pause");
	return 0;
}