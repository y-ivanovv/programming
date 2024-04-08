#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	forward_list<int> l;
	int n;
	cout << "N = ";
	cin >> n;
	cout << "Введите целые числа: ";
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		l.push_front(num);
		if (abs(num) < 2)
		{
			l.push_front(15);
		}
	}
	l.reverse();
	cout << "Ваш новый список: ";
	for (int& elem : l)
	{
		cout << elem << " ";
	}
	return 0;
}