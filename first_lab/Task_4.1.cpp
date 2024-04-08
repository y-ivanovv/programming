#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	forward_list<float> l;
	int n, count = 0;
	cout << "N = ";
	cin >> n;
	cout << "Введите вещественные числа: ";
	for (int i = 0; i < n; i++)
	{
		float num;
		cin >> num;
		l.push_front(num);
		if (num > 7)
		{
			count++;
		}
	}
	cout << "Количество элементов списка со значениями больше 7: " << count;
	return 0;
}