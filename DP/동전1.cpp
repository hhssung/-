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
	for (int i = 1; i <= n; i++)	//������ ������ �ϳ����� ���� �ݺ���
	{
		for (int j = arr[i]; j <= k; j++)	//�ش� ������ ��ġ~��ġ�� �ձ��� �ݺ���
		{
			dp[j] = dp[j] + dp[j - arr[i]];  // ex) 3�� ����� ���: ������ 3�� 3-�ش� ���� ��ġ ����� ��
		}
	}

	cout << dp[k];
	system("pause");
	return 0;
}