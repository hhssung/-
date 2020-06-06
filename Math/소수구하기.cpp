#include <iostream>

using namespace std;

int main(void)
{
	int arr[1000] = { 0 };
	arr[0] = 2;
	int t = 1;

	int xxx;
	for (int i = 3; i <= 1000; i++)
	{
		xxx = 0;
		for (int j = 0; j < t; j++)
		{
			if (i % arr[j] == 0)
			{
				xxx = 1;
				break;
			}
		}
		if (xxx != 1)
		{
			arr[t] = i;
			t++;
		}
	}

	int M, N;

	cin >> M >> N;

	if (M > 1000)
	{
		for (int i = M; i <= N; i++)
		{
			xxx = 0;
			for (int j = 0; j < t; j++)
			{
				if (i%arr[j] == 0)
				{
					xxx = 1;
					break;
				}
			}
			if (xxx != 1)
			{
				printf("%d\n", i);
			}
		}
	}
	else {
		if (N > 1000)
		{
			for (int i = M; i <= 1000; i++)
			{
				for (int j = 0; j < t; j++)
				{
					if (i == arr[j])
					{
						printf("%d\n", i);
							break;
					}
				}
			}
			for (int i = 1001; i <= N; i++)
			{
				xxx = 0;
				for (int j = 0; j < t; j++)
				{
					if (i%arr[j] == 0)
					{
						xxx = 1;
						break;
					}
				}
				if (xxx != 1)
				{
					printf("%d\n", i);
				}
			}

		}
		else {
			for (int i = M; i <= N; i++)
			{
				for (int j = 0; j < t; j++)
				{
					if (i == arr[j])
					{
						printf("%d\n", i);
							break;
					}
				}
			}

		}
	}

	system("pause");
	return 0;
}