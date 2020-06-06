#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(void)
{
	int arr[20000001] = { 0 };

	int N;
	scanf("%d", &N);
	int s;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &s);
		arr[s + 10000000]++;
	}
	int result[500001];

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &s);
		result[i] = arr[s + 10000000];
	}

	for (int i = 0; i < M; i++)
	{
		printf("%d ", result[i]);
	}

	//system("pause");
	return 0;
}