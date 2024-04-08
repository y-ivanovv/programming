#include <iostream>
#include <queue>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	queue<double> que;
	int n, neg = 0;
	cout << "N = ";
	cin >> n;
	cout << "Введите " << n << " чисел: ";
	for (int i = 0; i < n; i++)
	{
		double a;
		cin >> a;
		que.push(a);
		if (a < 0)
		{
			neg++;
		}
	}
	cout << "Кол-во отрицательных элементов: " << neg << endl;
	cout << "Данные очереди:" << endl;
	while (!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	return 0;
}