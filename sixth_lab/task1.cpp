#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <limits>
#include <ctime>

using namespace std;

// Структура для представления файла
struct File {
    string name;
    time_t creationDate;
    int accessCount;

    File(const string& n, time_t cDate, int aCount) : name(n), creationDate(cDate), accessCount(aCount) {}

    // Функция для вывода информации о файле
    void printInfo() const {
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &creationDate);
        cout << "Имя файла: " << name << endl;
        cout << "Дата создания: " << buffer; // Преобразование времени в строку
        cout << "Количество обращений: " << accessCount << endl;
    }
};

// Функция для отображения меню
void displayMenu() {
    cout << "\nМеню:" << endl;
    cout << "1. Формирование каталога файлов" << endl;
    cout << "2. Вывод каталога файлов" << endl;
    cout << "3. Удаление файлов по дате создания" << endl;
    cout << "4. Файл с наибольшим количеством обращений" << endl;
    cout << "0. Выйти" << endl;
    cout << "Выберите действие: ";
}

// Функция для начального формирования каталога файлов
void initializeCatalog(list<File>& catalog) {
    int n;
    cout << "Введите количество файлов: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода

    for (int i = 0; i < n; ++i) {
        string name;
        int day, month, year, accessCount;
        cout << "Введите имя файла: ";
        getline(cin, name);
        cout << "Введите дату создания (дд мм гггг): ";
        cin >> day >> month >> year;
        cout << "Введите количество обращений: ";
        cin >> accessCount;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода

        // Формирование времени
        struct tm tm = {};
        tm.tm_mday = day;
        tm.tm_mon = month - 1; // месяцы начинаются с 0
        tm.tm_year = year - 1900; // годы считаются с 1900
        time_t creationDate = mktime(&tm);

        catalog.emplace_back(name, creationDate, accessCount);
    }
}

// Функция для вывода каталога файлов
void displayCatalog(const list<File>& catalog) {
    if (catalog.empty()) {
        cout << "Каталог пуст." << endl;
    }
    else {
        for (const auto& file : catalog) {
            file.printInfo();
            cout << endl;
        }
    }
}

// Функция для удаления файлов по дате создания
void removeFilesByDate(list<File>& catalog, time_t date) {
    catalog.remove_if([date](const File& file) { return file.creationDate < date; });
    cout << "Удаление выполнено." << endl;
}

// Функция для нахождения файла с наибольшим количеством обращений
void findFileWithMaxAccess(const list<File>& catalog) {
    if (catalog.empty()) {
        cout << "Каталог пуст." << endl;
    }
    else {
        auto maxFile = max_element(catalog.begin(), catalog.end(), [](const File& a, const File& b) {
            return a.accessCount < b.accessCount;
            });
        cout << "Файл с наибольшим количеством обращений:" << endl;
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
            cout << "Введите дату (дд мм гггг): ";
            cin >> day >> month >> year;

            // Формирование времени
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
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Повторите попытку." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
