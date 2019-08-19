/*

2  NO
3  NO
4  YES 2 2
5  2 3
6  3 3
7  2 5
8  3 5
9  2 7
10 5 5
11 2 9 x

   - 4이상의 짝수는 두 소수로 나눌수 있음.
   - 4 이상의 홀수는 2를 뺀 후 그 값이 소수이면 가능

*/


#include <iostream>
#include <vector>

using namespace std;

bool calcprime(long long sum, vector<int> &result)
{
	int i = 1;
	long long T = result[1] * result[1];
	while (T <= sum)
	{
		if (sum%result[i] == 0)
		{
			return 0;
		}
		i++;
		T = (long long)result[i] * result[i];	// 이부분에서 형변환 안해서 ㅈㄴ틀림
	}
	return 1;	//소수
}


int main(void)
{
	iostream::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);

	int n = 2000000;
	vector<bool>arr(n + 1, true);
	vector<int>result;

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == true)
		{
			result.push_back(i);
			for (int j = 1; i*j <= n; j++)
			{
				arr[i*j] = false;
			}
		}
	}		// 1~2000000까지의 소수들


	result.push_back(2000001);

	int T;
	cin >> T;

	long long num1;
	long long num2;
	long long sum;

	for (int i = 0; i < T; i++)
	{
		cin >> num1;
		cin >> num2;
		sum = num1 + num2;
		if (sum == 2 || sum == 3)
		{
			cout << "NO" << endl;
		}
		else if (sum % 2 == 0)
		{
			cout << "YES" << endl;
		}
		else {
			sum -= 2;
			if (calcprime(sum, result) == 1)
			{
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}

		}

	}




	//system("pause");
	return 0;
}