#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	iostream::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);

	int n;
	cin >> n;

	int drink[10000];
	int dp[10000];


	for (int i = 0; i < n; i++)
	{
		cin >> drink[i];
	}

	dp[0] = drink[0];
	dp[1] = drink[0] + drink[1];
	dp[2] = max(drink[0] + drink[2], drink[1] + drink[2]);
	dp[2] = max(dp[2], dp[1]); //여기서틀렸었음
	
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + drink[i], dp[i - 3] + drink[i - 1] + drink[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[n - 1] << endl;

	system("pause");
	return 0;
}	