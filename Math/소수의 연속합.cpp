#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


using namespace std;

int main(void)
{
	int N = 4000000;
	int NN;
	cin >> NN;
	vector<bool>arr(N+1, true);	//bool형의 N+1 메모리를 가진 arr 만들기
	vector<int>result;
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] == true) {
			result.push_back(i);
			for (int j = 1; i*j <= N; j++)
			{
				arr[i*j] = false;	//i의 배수 check
			}

		}
	}
	
	result.push_back(99999999);
	int sum;
	int first = 0;	//first: result[0]=2
	int temp;
	int cases = 0;

	while (result[first]<=NN)
	{
		sum = 0;
		temp = first;
		while (sum < NN)
		{
			sum += result[temp];
			temp++;
		}
		if (sum == NN)
		{
			cases++;
		}
		first++;
	}

	printf("%d", cases);

	/*for (auto &x : result) {
		printf("%d ", x);
	}*/


	system("pause");
	return 0;
}
