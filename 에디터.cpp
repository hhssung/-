#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	iostream::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string TT;	//문자열 받음
	int cursor;	//커서위치
	int N;	//명령 개수
	char operation;
	cin >> TT;
	cursor = TT.size();
	
	stack<char>right;

	cin >> N;
	char input[600001];
	for (int i = 0; i < cursor; i++)
	{
		input[i] = TT[i];
	}
	
	for (int i = 1; i <= N; i++)
	{
		cin >> operation;
		switch (operation)
		{
		case 'L':
			if (cursor == 0)
			{
				break;
			}
			right.push(input[cursor-1]);
			cursor--;
			break;

		case 'D':
			if (right.empty())
			{
				break;
			}
			input[cursor]=right.top();
			right.pop();
			cursor++;
			break;

		case 'B':
			if (cursor == 0)
			{
				break;
			}
			cursor--;
			break;

		case 'P':
			cin >> input[cursor];
			cursor++;
			break;
		}
	}

	for (int i = 0; i < cursor; i++)
	{
		cout << input[i];
	}
	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}

	system("pause");
	return 0;
}