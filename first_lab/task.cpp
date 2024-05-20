#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	ifstream file_1("a.txt");
	ofstream file_2("b.txt");

	char old_symbol, new_symbol;

	cout << "Введите символ, который вы хотите заменить: " << endl;
	cin >> old_symbol;
	cout << "Введите символ, на который вы хотите заменить старый: " << endl;
	cin >> new_symbol;

	if (!file_1.is_open() or !file_2.is_open())
	{
		cerr << "Ошибка открытия файла" << endl;
		return 1;
	}

	char symbol;
	string line;
	while (getline(file_1, line))
	{
		for (char& symbol : line)
		{
			if (symbol == old_symbol)
			{
				symbol = new_symbol;
			}
		}
		file_2 << line << endl;
	}

	file_1.close();
	file_2.close();

	cout << "Замена символов произведена" << endl;

	return 0;
