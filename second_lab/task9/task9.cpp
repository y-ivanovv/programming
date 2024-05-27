#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring> // ��� ������� strcpy

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
        throw runtime_error("�� ������� ������� ���� ��� ������: " + filename);
    }

    for (const auto& student : students) {
        file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }
    file.close();
}

vector<Student> readStudents(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("�� ������� ������� ���� ��� ������: " + filename);
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
        cout << "���: " << student.name << '\n';
        cout << "������: " << student.groupNumber << '\n';
        cout << "������: " << student.grades[0] << ", " << student.grades[1] << ", " << student.grades[2] << '\n';
        cout << "���������: " << student.scholarship << '\n';
        cout << "--------------------------\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    string filename = "products.dat";

    // �������� � ������ ��������� � ����
    vector<Student> students = {
        {"������ �.�.", 101, {5, 4, 4}, 1000.0},
        {"������ �.�.", 102, {3, 4, 5}, 1000.0},
        {"������� �.�.", 103, {5, 5, 5}, 1000.0},
    };

    writeStudents(filename, students);

    // ������ ������ �� ����� � ����� �� �����
    vector<Student> fileData = readStudents(filename);
    cout << "�������� �� ���������:\n";
    printStudents(fileData);

    // ���������� ���������
    updateScholarships(fileData);

    // ������ ���������� ������ ������� � ����
    writeStudents(filename, fileData);

    // ������ ���������� ������ �� ����� � ����� �� �����
    fileData = readStudents(filename);
    cout << "�������� ����� ���������:\n";
    printStudents(fileData);

    return 0;
}