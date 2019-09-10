#include <iostream>

using namespace std;

int main(void)
{
	iostream::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	int N;
	int arr[10001];
	
	cin >> N;

	long long coldeye = N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int B, C;
	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		arr[i] -= B;
	}

	for (int i = 0; i < N; i++)
	{
		if (arr[i] <= 0)
		{
			continue;
		}
		coldeye += (arr[i]/C);
		if (arr[i] % C != 0)
		{
			coldeye++;
		}
	}

	cout << coldeye << endl;

	system("pause");
	return 0;
}