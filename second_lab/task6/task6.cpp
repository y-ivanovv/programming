#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isPerfectSquare(int num) {
    if (num < 0) return false;
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}

void process(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);
    int num;

    if (!inputFile) {
        cerr << "Ошибка открытия входного файла " << inputFilename << endl;
        return;
    }

    if (!outputFile) {
        cerr << "Ошибка открытия выходного файла " << outputFilename << endl;
        return;
    }

    while (inputFile >> num) {
        if (isPerfectSquare(num)) {
            outputFile << num << endl;
        }
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    setlocale(LC_ALL, "ru");

    string inputFilename = "a.txt";
    string outputFilename = "b.txt";

    process(inputFilename, outputFilename);

    cout << "Точные квадраты записаны в " << outputFilename << endl;

    return 0;
}