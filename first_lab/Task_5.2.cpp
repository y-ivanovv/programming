#include <iostream> 
#include <list> 
#include <string> 

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	list<char> l;
	string s;
	cout << "Введите символы: ";
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		l.push_back(s[i]);
	}
	auto it = l.begin();
	while (it != l.end())
	{
		if (*it == '&')
		{
			if (next(it) != l.end())
			{
				it = l.erase(next(it));
			}
			else
			{
				break;
			}
		}
		else
		{
			it++;
		}
	}
	for (char& elem : l)
	{
		cout << elem << " ";
	}
	return 0;
}