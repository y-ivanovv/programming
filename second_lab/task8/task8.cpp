#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype> // ��� ������� toupper

using namespace std;

void writeToFile(const string& filename, const vector<char>& data) {
    ofstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("�� ������� ������� ���� ��� ������: " + filename);
    }
    file.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(char));
    file.close();
}

vector<char> readFromFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("�� ������� ������� ���� ��� ������: " + filename);
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

    // ���� ��������
    cout << "������� ������� ���������� ��������: ";
    string input;
    getline(cin, input);
    vector<char> data(input.begin(), input.end());

    // ������ ������ � �������� ����
    writeToFile(filename, data);

    // ������ ������ �� ����� � ����� �� �����
    vector<char> fileData = readFromFile(filename);
    cout << "������� �� ���������: ";
    printData(fileData);

    // �������������� �������� � ���������
    convertToUpper(fileData);

    // ������ ���������� ������ ������� � ����
    writeToFile(filename, fileData);

    // ������ ���������� ������ �� ����� � ����� �� �����
    fileData = readFromFile(filename);
    cout << "������� ����� ���������: ";
    printData(fileData);

    return 0;
}