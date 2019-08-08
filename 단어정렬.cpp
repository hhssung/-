#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool myfunc(string i, string j)
{
	if (i.length() < j.length())
	{
		return 1;
	}
	else if(i.length()==j.length()){
		return (i < j);
	}
	else {
		return 0;
	}

}

int main(void)
{
	iostream::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string sss[20000];
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> sss[i];
	}

	sort(sss, sss + N, myfunc);

	for (int i = 0; i < N; i++)
	{
		if (sss[i - 1] != sss[i])
		{
			cout << sss[i] << endl;

		}
	}


	system("pause");
	return 0;
}