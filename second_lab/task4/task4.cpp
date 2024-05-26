#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	ifstream file("a.txt");
	
	if (!file.is_open())
	{
		cerr << "Не удалось открыть файл" << endl;
		return 1;
	}

	int num;
	int index = 1;
	int max_number = -125;
	while (file >> num)
	{
		if (index % 3 == 0 && num > max_number)
		{
			max_number = num;
		}
		index++;
	}

	file.close();

	if (max_number == -125)
	{
		cout << "В файле нет элементов с индексами, кратными трем" << endl;
	}
	else
	{
		cout << "Наибольший элемент файла среди элементов, номера которых кратны трем: " << max_number << endl;
	}

	return 0;
}