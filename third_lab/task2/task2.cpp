#include <iostream>
#include <string>
#include <sstream>

using namespace std; 

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Конструктор по умолчанию
    Date() : day(1), month(1), year(2000) {}

    // Конструктор перезагрузки с параметрами
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Деструктор для освобождения памяти
    ~Date() {
        cout << "Объект даты уничтожен\n";
    }

    // Функция обработки данных: определить, совпадают ли номер месяца и число дня
    bool isMonthDayMatch() const {
        return (day == month);
    }

    // Функция обработки данных: увеличить дату на один месяц
    void incrementMonth() {
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    // Функция формирования строки информации об объекте
    string getInfo() const {
        stringstream ss;
        ss << "Дата: " << day << "." << month << "." << year;
        return ss.str();
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    // Создаем объект класса Date через указатель
    Date* datePtr = new Date(10, 5, 2024);

    // Выводим информацию о дате
    cout << "Дата: " << datePtr->getInfo() << endl;

    // Проверяем совпадение номера месяца и числа дня
    if (datePtr->isMonthDayMatch()) {
        cout << "Номер месяца и число дня совпадают\n";
    }
    else {
        cout << "Номер месяца и число дня не совпадают\n";
    }

    // Увеличиваем дату на один месяц
    datePtr->incrementMonth();
    cout << "Дата после увеличения на один месяц: " << datePtr->getInfo() << endl;

    // Освобождаем выделенную память
    delete datePtr;

    return 0;
}
