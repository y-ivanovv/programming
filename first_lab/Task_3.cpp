#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> s;
	n = s.size();
	stack<char> st;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(' or s[i] == '[' or s[i] == '{')
		{
			st.push(s[i]);
		}
		else
		{
			if (st.size() == 0)
			{
				cout << "No";
				return 0;
			}
			if (s[i] == ')' and st.top() == '(')
			{
				st.pop();
			}
			else if (s[i] == ']' and st.top() == '[')
			{
				st.pop();
			}
			else if (s[i] == '}' and st.top() == '{')
			{
				st.pop();
			}
			else
			{
				cout << "No";
				return 0;
			}
		}
	}
	if (st.size() == 0)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}