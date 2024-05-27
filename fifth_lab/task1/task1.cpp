#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data; // std::vector ��� ��������� �����

public:
    // ���������� �������� � ����
    void push(const T& value) {
        data.push_back(value);
    }

    // �������� �������� �� �����
    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
        else {
            cout << "���� ����. ���������� ������� �������." << endl;
        }
    }

    // ��������� �������� �������� �����
    T top() const {
        if (!data.empty()) {
            return data.back();
        }
        else {
            throw out_of_range("���� ����. ��� �������� ��������.");
        }
    }

    // ��������, ���� �� ����
    bool empty() const {
        return data.empty();
    }

    // ��������� ������� �����
    size_t size() const {
        return data.size();
    }
};

void displayMenu() {
    cout << "\n����:" << endl;
    cout << "1. �������� ������� � ����" << endl;
    cout << "2. ������� ������� �� �����" << endl;
    cout << "3. �������� ������� ������� �����" << endl;
    cout << "4. ���������, ���� �� ����" << endl;
    cout << "5. �������� ������ �����" << endl;
    cout << "0. �����" << endl;
    cout << "�������� ��������: ";
}

int main() {
    setlocale(LC_ALL, "ru");

    Stack<int> intStack;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "������� �������� ��� ���������� � ����: ";
            cin >> value;
            intStack.push(value);
            cout << "�������� ��������� � ����." << endl;
            break;
        }
        case 2: {
            try {
                intStack.pop();
                cout << "������� ������� ������ �� �����." << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            try {
                cout << "������� ������� �����: " << intStack.top() << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            if (intStack.empty()) {
                cout << "���� ����." << endl;
            }
            else {
                cout << "���� �� ����." << endl;
            }
            break;
        }
        case 5: {
            cout << "������ �����: " << intStack.size() << endl;
            break;
        }
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