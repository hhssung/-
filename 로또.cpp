#include <iostream>

using namespace std;

void DFS(int temp, int k, int pos, int arr[14], int arrsave[6])
{
	if (temp < 6)
	{
		if (pos < k)
		{
			for (int i = pos; i < k; i++)
			{
				arrsave[temp] = arr[i];
				DFS(temp + 1, k, i + 1, arr, arrsave);
			}
		}
	}
	else {
		for (int i = 0; i < 6; i++)
		{
			printf("%d ", arrsave[i]);
		}
		cout << endl;
	}
}


int main()
{
	int arr[14] = { 0 };
	int arrsave[6] = { 0 };

	int k = 999999;
	int num;
	while (k != 0)
	{
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}

		DFS(0, k, 0, arr, arrsave);
		cout << endl;
	}


	//system("pause");
	return 0;
}