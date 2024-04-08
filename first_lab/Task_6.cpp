#include <iostream>
#include <list>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	list<int> l;
	int n;
	cout << "N = ";
	cin >> n;
	cout << "Введите ваши числа: ";
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		l.push_back(num);
	}
	l.reverse();
	for (auto it = l.begin(); it != l.end(); it++)
	{
		if (*it < 15)
		{
			l.erase(it);
			break;
		}
	}
	l.reverse();
	cout << "Новый список: ";
	for (int& elem : l)
	{
		cout << elem << " ";
	}
	return 0;
}
