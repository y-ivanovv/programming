#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring> // Для функции strcpy

using namespace std;

struct Student {
    char name[50];
    int groupNumber;
    int grades[3];
    double scholarship;
};

void writeStudents(const string& filename, const vector<Student>& students) {
    ofstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("Не удалось открыть файл для записи: " + filename);
    }

    for (const auto& student : students) {
        file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }
    file.close();
}

vector<Student> readStudents(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("Не удалось открыть файл для чтения: " + filename);
    }

    vector<Student> students;
    Student student;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        students.push_back(student);
    }
    file.close();
    return students;
}

void updateScholarships(vector<Student>& students) {
    for (auto& student : students) {
        bool hasThree = false;
        for (int grade : student.grades) {
            if (grade == 3) {
                hasThree = true;
                break;
            }
        }
        if (!hasThree) {
            student.scholarship *= 1.3;
        }
    }
}

void printStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "ФИО: " << student.name << '\n';
        cout << "Группа: " << student.groupNumber << '\n';
        cout << "Оценки: " << student.grades[0] << ", " << student.grades[1] << ", " << student.grades[2] << '\n';
        cout << "Стипендия: " << student.scholarship << '\n';
        cout << "--------------------------\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    string filename = "products.dat";

    // Создание и запись студентов в файл
    vector<Student> students = {
        {"Иванов И.И.", 101, {5, 4, 4}, 1000.0},
        {"Петров П.П.", 102, {3, 4, 5}, 1000.0},
        {"Сидоров С.С.", 103, {5, 5, 5}, 1000.0},
    };

    writeStudents(filename, students);

    // Чтение данных из файла и вывод на экран
    vector<Student> fileData = readStudents(filename);
    cout << "Студенты до изменения:\n";
    printStudents(fileData);

    // Обновление стипендий
    updateScholarships(fileData);

    // Запись измененных данных обратно в файл
    writeStudents(filename, fileData);

    // Чтение измененных данных из файла и вывод на экран
    fileData = readStudents(filename);
    cout << "Студенты после изменения:\n";
    printStudents(fileData);

    return 0;
}
