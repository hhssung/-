#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	int arr[300];
	int dp[300];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];
	dp[1] = max(arr[1], arr[0]+arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < N; i++)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	}

	cout << dp[N - 1] << endl;
	system("pause");

	return 0;
}