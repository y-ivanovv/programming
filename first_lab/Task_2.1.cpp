#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
string s;

void push(string s)
{
	v.push_back(s);
}

void pop()
{
	v.pop_back();
}

void print()
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int count()
{
	int n = v.size();
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].length() == 2)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "RU");
	push("abc");
	push("fx");
	push("glc");
	push("hi");
	push("gogo");
	print();
	pop();
	push("the end");
	print();
	cout << "\nКол-во строк из 2 символов: " << count() << endl;
	return 0;
}
