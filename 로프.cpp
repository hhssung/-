#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int arr[100000];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+N);

	int maxx = -1;

	for (int i = N - 1; i >= 0; i--)
	{
		int k = arr[i] * (N - i);
		if (k > maxx)
		{
			maxx = k;
		}
	}

	cout << maxx;
	system("pause");
	return 0;
}