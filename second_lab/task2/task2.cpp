#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	ifstream file_1("a.txt");
	ifstream file_2("b.txt");

	if (!file_1.is_open() or !file_2.is_open())
	{
		cerr << "Ошибка открытия файла" << endl;
		return 1;
	}

	int count = 0;
	double num;

	while (file_1 >> num)
	{
		if (num == 0)
		{
			count++;
		}
	}
	while (file_2 >> num)
	{
		if (num == 0)
		{
			count++;
		}
	}

	file_1.close();
	file_2.close();
	
	cout << "Кол-во нулевых элементов: " << count << endl;

	return 0;
}