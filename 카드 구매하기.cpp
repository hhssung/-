#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int arr[1001];
	int dp[1001];
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	


	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i - j] + arr[j], dp[i]);

		}
	}
	
	cout << dp[N];
	system("pause");
	return 0;
}