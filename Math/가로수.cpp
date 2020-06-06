#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	iostream::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	int arr[100000];
	int arrdif[99999];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr + N);

	for (int i = 0; i < N-1; i++)
	{
		arrdif[i] = arr[i + 1] - arr[i];
	}
	
	sort(arrdif, arrdif + N - 1);

	int armin;
	int min=0;
	int check=1;

	/*for (int i = 0; i < N - 1; i++)
	{
		cout << arrdif[i] << endl;
	}*/
	
	for (int i = 1; i <= arrdif[0]; i++)
	{
		check = 2;
		if (arrdif[0]%i == 0)
		{
			armin = arrdif[0] / i;
			for (int j = 1; j < N - 1; j++)
			{
				if (arrdif[j] % armin != 0)
				{
					check = 1;
					break;
				}
			}
			if (check != 1)
			{
				check = 0;
			}
		}
		if (check == 0)
		{
			//cout << armin << endl;
			for (int j = 0; j < N - 1; j++)
			{
				
				if (arrdif[j] != armin)
				{
					min = min - 1 + (arrdif[j] / armin);
				}
			}
			break;
		}
	}

	cout << min << endl;

	system("pause");
	return 0;
}