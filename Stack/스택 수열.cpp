#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

/* 

cout, cin => printf, scanf로 하니까 맞았음

*/

int main()
{
	//iostream::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	int n;
	scanf("%d", &n);
	int arr[100001];
	char calc[200001];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}

	stack <int> gg;
	int pushval = 1;
	int arrval = 1;
	int yesorno = 1;
	int calcval = 1;
	while (arrval <= arr[pushval])
	{
		calc[calcval] = '+';
		gg.push(arrval);
		arrval++;
		calcval++;
	}
	calc[calcval] = '-';
	calcval++;
	gg.pop();
	pushval++;
	while (arrval <= n)
	{
		if (arr[pushval] > arr[pushval - 1])
		{
			while (arrval <= arr[pushval])
			{
				calc[calcval] = '+';
				gg.push(arrval);
				arrval++;
				calcval++;
			}
			calc[calcval] = '-';
			calcval++;
			gg.pop();
			pushval++;
		}
		else {
			if (gg.top() == arr[pushval])
			{
				calc[calcval] = '-';
				calcval++;
				gg.pop();
				pushval++;
			}
			else {
				yesorno = 0;
				break;
			}
		}
	}
	if (yesorno == 1)
	{
		while (!gg.empty())
		{
			if (gg.top() == arr[pushval])	//여기서 틀렸음. arr[pushval-1]-1==arr[pushval]이라했었음
			{
				gg.pop();
				calc[calcval] = '-';
				calcval++;
				pushval++;
			}
			else {
				yesorno = 0;
				break;
			}
		}
	}



	if (yesorno == 0)
	{
		printf("NO");
	}
	else {
		for (int i = 1; i <= 2 * n; i++)
		{
			printf("%c\n", calc[i]);
		}
	}

	system("pause");
	return 0;
}