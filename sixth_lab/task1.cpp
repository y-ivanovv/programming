#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <limits>
#include <ctime>

using namespace std;

// ��������� ��� ������������� �����
struct File {
    string name;
    time_t creationDate;
    int accessCount;

    File(const string& n, time_t cDate, int aCount) : name(n), creationDate(cDate), accessCount(aCount) {}

    // ������� ��� ������ ���������� � �����
    void printInfo() const {
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &creationDate);
        cout << "��� �����: " << name << endl;
        cout << "���� ��������: " << buffer; // �������������� ������� � ������
        cout << "���������� ���������: " << accessCount << endl;
    }
};

// ������� ��� ����������� ����
void displayMenu() {
    cout << "\n����:" << endl;
    cout << "1. ������������ �������� ������" << endl;
    cout << "2. ����� �������� ������" << endl;
    cout << "3. �������� ������ �� ���� ��������" << endl;
    cout << "4. ���� � ���������� ����������� ���������" << endl;
    cout << "0. �����" << endl;
    cout << "�������� ��������: ";
}

// ������� ��� ���������� ������������ �������� ������
void initializeCatalog(list<File>& catalog) {
    int n;
    cout << "������� ���������� ������: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������ �����

    for (int i = 0; i < n; ++i) {
        string name;
        int day, month, year, accessCount;
        cout << "������� ��� �����: ";
        getline(cin, name);
        cout << "������� ���� �������� (�� �� ����): ";
        cin >> day >> month >> year;
        cout << "������� ���������� ���������: ";
        cin >> accessCount;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������ �����

        // ������������ �������
        struct tm tm = {};
        tm.tm_mday = day;
        tm.tm_mon = month - 1; // ������ ���������� � 0
        tm.tm_year = year - 1900; // ���� ��������� � 1900
        time_t creationDate = mktime(&tm);

        catalog.emplace_back(name, creationDate, accessCount);
    }
}

// ������� ��� ������ �������� ������
void displayCatalog(const list<File>& catalog) {
    if (catalog.empty()) {
        cout << "������� ����." << endl;
    }
    else {
        for (const auto& file : catalog) {
            file.printInfo();
            cout << endl;
        }
    }
}

// ������� ��� �������� ������ �� ���� ��������
void removeFilesByDate(list<File>& catalog, time_t date) {
    catalog.remove_if([date](const File& file) { return file.creationDate < date; });
    cout << "�������� ���������." << endl;
}

// ������� ��� ���������� ����� � ���������� ����������� ���������
void findFileWithMaxAccess(const list<File>& catalog) {
    if (catalog.empty()) {
        cout << "������� ����." << endl;
    }
    else {
        auto maxFile = max_element(catalog.begin(), catalog.end(), [](const File& a, const File& b) {
            return a.accessCount < b.accessCount;
            });
        cout << "���� � ���������� ����������� ���������:" << endl;
        maxFile->printInfo();
    }
}

int main() {
    setlocale(LC_ALL, "ru"); 

    list<File> catalog;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            initializeCatalog(catalog);
            break;
        case 2:
            displayCatalog(catalog);
            break;
        case 3: {
            int day, month, year;
            cout << "������� ���� (�� �� ����): ";
            cin >> day >> month >> year;

            // ������������ �������
            struct tm tm = {};
            tm.tm_mday = day;
            tm.tm_mon = month - 1;
            tm.tm_year = year - 1900;
            time_t date = mktime(&tm);

            removeFilesByDate(catalog, date);
            break;
        }
        case 4:
            findFileWithMaxAccess(catalog);
            break;
        case 0:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� �����. ��������� �������." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
