#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	forward_list<float> l;
	int n;
	cout << "N = ";
	cin >> n;
	cout << "Введите целые числа: ";
	for (int i = 0; i < n; i++)
	{
		float num;
		cin >> num;
		l.push_front(num);
		if (num < 0)
		{
			l.push_front(1.5);
		}
	}
	l.reverse();
	cout << "Ваш новый список: ";
	for (float& elem : l)
	{
		cout << elem << " ";
	}
	return 0;
}
