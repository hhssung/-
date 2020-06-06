#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int testcase;
	cin >> testcase;
	int N, M;

	int arr[100];
	int arr2[100];

	int t;
	int count;
	for (int i = 0; i < testcase; i++)
	{
		cin >> N >> M;
		count = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
		}
		for (int j = 0; j < N; j++)
		{
			arr2[j] = arr[j];
		}
		sort(arr2, arr2 + N);



		while (1)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[j] == arr2[N - 1 - count])
				{
					arr[j] = 0;
					count++;
				}
				if (arr[M] == 0)
				{
					cout << count << endl;
					break;
				}
			}
			if (arr[M] == 0)
			{

				break;
			}
		}
		for (int j = 0; j < N; j++)
		{
			arr[i] = 0;
			arr[j] = 0;
		}



	}
	return 0;

}