#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{

	int n = 1000000;
	vector<bool>arr(n + 1, true);
	vector<int>result;

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == true)
		{
			result.push_back(i);
			for (int j = 1; i*j <= n; j++)
			{
				arr[i*j] = false;
			}
		}
	}

	bool arr2[1000001] = { 0 };
	for (auto &x : result)
	{
		arr2[x] = 1;
	}
	
	int ang=1;

	while (ang != 0)
	{
		scanf("%d", &ang);
		for (int i = 1; result[i] <= ang / 2; i++)
		{
			if (arr2[ang-result[i]] == 1)
			{
				printf("%d = %d + %d\n", ang, result[i], ang - result[i]);
				break;
			}
		}

	}


	system("pause");
	return 0;
}