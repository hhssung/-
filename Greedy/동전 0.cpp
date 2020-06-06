#include <iostream>

using namespace std;

int main(void)
{
	int N, K;
	int arr[10];
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int coin = 0;

	for (int i = N - 1; i >= 0; i--)
	{
			coin += (K / arr[i]);
			K = K % arr[i];

	}
	cout << coin << endl;

	system("pause");
	return 0;
}