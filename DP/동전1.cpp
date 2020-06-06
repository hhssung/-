#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int arr[101];
	int dp[10001] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)	//각각의 동전들 하나씩에 대해 반복문
	{
		for (int j = arr[i]; j <= k; j++)	//해당 동전의 가치~가치의 합까지 반복문
		{
			dp[j] = dp[j] + dp[j - arr[i]];  // ex) 3을 만드는 방법: 기존의 3에 3-해당 동전 가치 경우의 수
		}
	}

	cout << dp[k];
	system("pause");
	return 0;
}