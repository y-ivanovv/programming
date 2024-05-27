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
    // ����������� �� ���������
    Date() : day(1), month(1), year(2000) {}

    // ����������� ������������ � �����������
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // ���������� ��� ������������ ������
    ~Date() {
        cout << "������ ���� ���������\n";
    }

    // ������� ��������� ������: ����������, ��������� �� ����� ������ � ����� ���
    bool isMonthDayMatch() const {
        return (day == month);
    }

    // ������� ��������� ������: ��������� ���� �� ���� �����
    void incrementMonth() {
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    // ������� ������������ ������ ���������� �� �������
    string getInfo() const {
        stringstream ss;
        ss << "����: " << day << "." << month << "." << year;
        return ss.str();
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    // ������� ������ ������ Date ����� ���������
    Date* datePtr = new Date(10, 5, 2024);

    // ������� ���������� � ����
    cout << "����: " << datePtr->getInfo() << endl;

    // ��������� ���������� ������ ������ � ����� ���
    if (datePtr->isMonthDayMatch()) {
        cout << "����� ������ � ����� ��� ���������\n";
    }
    else {
        cout << "����� ������ � ����� ��� �� ���������\n";
    }

    // ����������� ���� �� ���� �����
    datePtr->incrementMonth();
    cout << "���� ����� ���������� �� ���� �����: " << datePtr->getInfo() << endl;

    // ����������� ���������� ������
    delete datePtr;

    return 0;
}
