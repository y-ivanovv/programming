#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype> // Для функции toupper

using namespace std;

void writeToFile(const string& filename, const vector<char>& data) {
    ofstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("Не удалось открыть файл для записи: " + filename);
    }
    file.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(char));
    file.close();
}

vector<char> readFromFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("Не удалось открыть файл для чтения: " + filename);
    }
    file.seekg(0, ios::end);
    streamsize size = file.tellg();
    file.seekg(0, ios::beg);

    vector<char> data(size);
    file.read(data.data(), size);
    file.close();
    return data;
}

void convertToUpper(vector<char>& data) {
    for (char& c : data) {
        c = toupper(static_cast<unsigned char>(c));
    }
}

void printData(const vector<char>& data) {
    for (char c : data) {
        cout << c;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    string filename = "products.dat";

    // Ввод символов
    cout << "Введите символы латинского алфавита: ";
    string input;
    getline(cin, input);
    vector<char> data(input.begin(), input.end());

    // Запись данных в бинарный файл
    writeToFile(filename, data);

    // Чтение данных из файла и вывод на экран
    vector<char> fileData = readFromFile(filename);
    cout << "Символы до изменения: ";
    printData(fileData);

    // Преобразование символов в заглавные
    convertToUpper(fileData);

    // Запись измененных данных обратно в файл
    writeToFile(filename, fileData);

    // Чтение измененных данных из файла и вывод на экран
    fileData = readFromFile(filename);
    cout << "Символы после изменения: ";
    printData(fileData);

    return 0;
}
