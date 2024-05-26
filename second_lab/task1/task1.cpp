#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	ifstream file("a.txt");

	if (!file.is_open())
	{
		cerr << "Ошибка открытия файла" << endl;
		return 1;
	}

	int count = 0;
	double num, sum = 0;

	while (file >> num)
	{
		if (num == 0)
		{
			count++;
		}
		else if (num < 0)
		{
			sum += num;
		}
	}

	file.close();

	cout << "Кол-во нулевых элементов: " << count << endl;
	cout << "Сумма отреицательных элементов: " << sum << endl;

	return 0;
}