#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	iostream::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	stack<char> paren;
	int T;
	cin >> T;
	string x;
	int j;
	int check;
	for (int i = 0; i < T; i++)
	{
		cin >> x;
		j = 0;
		check = 0;
		while (x[j] != NULL)
		{
			if (x[j] == '(')
			{
				paren.push(x[j]);
			}
			else if(x[j]==')'){
				if (paren.empty())
				{
					check = 1;
					break;
				}
				else {
					paren.pop();
				}
			}
			j++;
		}
		if (paren.empty() && check==0)
		{
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		while (!paren.empty())
		{
			paren.pop();
		}

	}

	//system("pause");
	return 0;
}