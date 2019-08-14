#include <iostream>

using namespace std;

//dp »ç¿ë

int main()
{
	int N;
	cin >> N;

	int arr[10001] = { 0 };

	int s;
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d",&s);
		arr[s]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 1; j <= arr[i]; j++)
		{
			printf("%d\n", i);
		}
	}


	system("pause");
	return 0;
}