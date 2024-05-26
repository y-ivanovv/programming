#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Student {
	string lastname;
	string firstname;
	string middlename;
	char gender;
	string nationality;
	int height;
	int weight;
	string birthdate;
	string phonenumber;
	string adress;
	string university;
	int course;
	string group;
 	int averagegrade;
	string speciality;
};

vector<Student> readfile(const string& filename) {
	ifstream file(filename);
	vector<Student> students;
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		Student student;

		getline(ss, student.lastname, ';');
		getline(ss, student.firstname, ';');
		getline(ss, student.middlename, ';');
		ss >> student.gender; ss.ignore(1, ';');
		getline(ss, student.nationality, ';');
		ss >> student.height; ss.ignore(1, ';');
		ss >> student.weight; ss.ignore(1, ';');
		getline(ss, student.birthdate, ';');
		getline(ss, student.phonenumber, ';');
		getline(ss, student.adress, ';');
		getline(ss, student.university, ';');
		ss >> student.course; ss.ignore(1, ';');
		getline(ss, student.group, ';');
		ss >> student.averagegrade; ss.ignore(1, ';');
		getline(ss, student.speciality, ';');

		students.push_back(student);
	}
	file.close();
	return students;
}

void savefile(const vector<Student>& students, const string& filename) {
	ofstream file(filename);

	for (const auto& student : students) {
		if (student.averagegrade < 70) {
			file << student.lastname << ";"
				<< student.firstname << ";"
				<< student.middlename << ";"
				<< student.gender << ";"
				<< student.nationality << ";"
				<< student.height << ";"
				<< student.weight << ";"
				<< student.birthdate << ";"
				<< student.phonenumber << ";"
				<< student.adress << ";"
				<< student.university << ";"
				<< student.course << ";"
				<< student.group << ";"
				<< student.averagegrade << ";"
				<< student.speciality << "\n";
		}
	}
	file.close();
}

int main() {
	setlocale(LC_ALL, "ru");
	string inputfile = "a.txt";
	string outputfile = "b.txt";

	vector<Student> students = readfile(inputfile);
	savefile(students, outputfile);

	cout << "Данные о студентах со средним балло ниже 70 сохранены в: " << outputfile << endl;

	return 0;
}
