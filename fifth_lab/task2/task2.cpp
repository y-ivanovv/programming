#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data; // std::vector ��� �������� ��������� �����

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

    // ����� ���� ��������� �����
    void printAll() const {
        for (const auto& item : data) {
            cout << item << endl;
        }
    }
};

// ��������� ��� �������� ������
struct TicketRequest {
    string destination;
    string flightNumber;
    string passengerName;
    string departureDate;

    // ���������� ��������� ������ ��� �������� ����������� ������
    friend ostream& operator<<(ostream& os, const TicketRequest& request) {
        os << "����� ����������: " << request.destination << endl;
        os << "����� �����: " << request.flightNumber << endl;
        os << "��������: " << request.passengerName << endl;
        os << "���� ������: " << request.departureDate << endl;
        return os;
    }
};

void displayMenu() {
    cout << "\n����:" << endl;
    cout << "1. �������� ������" << endl;
    cout << "2. ������� ��������� ������" << endl;
    cout << "3. �������� ��������� ������" << endl;
    cout << "4. �������� ��� ������" << endl;
    cout << "5. ����� ������ �� ������ ����� � ���� ������" << endl;
    cout << "0. �����" << endl;
    cout << "�������� ��������: ";
}

int main() {
    setlocale(LC_ALL, "ru"); 

    Stack<TicketRequest> ticketStack;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            TicketRequest request;
            cout << "������� ����� ����������: ";
            cin >> ws; // ������������ ������� ����� ������ ������
            getline(cin, request.destination);
            cout << "������� ����� �����: ";
            getline(cin, request.flightNumber);
            cout << "������� ������� � �������� ���������: ";
            getline(cin, request.passengerName);
            cout << "������� �������� ���� ������ (��.��.����): ";
            getline(cin, request.departureDate);
            ticketStack.push(request);
            cout << "������ ���������." << endl;
            break;
        }
        case 2: {
            try {
                ticketStack.pop();
                cout << "��������� ������ �������." << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            try {
                cout << "��������� ������:" << endl;
                cout << ticketStack.top() << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            cout << "��� ������:" << endl;
            ticketStack.printAll();
            break;
        }
        case 5: {
            string flightNumber, departureDate;
            cout << "������� ����� �����: ";
            cin >> ws;
            getline(cin, flightNumber);
            cout << "������� ���� ������ (��.��.����): ";
            getline(cin, departureDate);
            cout << "������ � ������� ����� " << flightNumber << " � ����� ������ " << departureDate << ":" << endl;
            Stack<TicketRequest> tempStack; // ��������� ���� ��� ������
            bool found = false;
            while (!ticketStack.empty()) {
                if (ticketStack.top().flightNumber == flightNumber && ticketStack.top().departureDate == departureDate) {
                    cout << ticketStack.top() << endl;
                    found = true;
                }
                tempStack.push(ticketStack.top());
                ticketStack.pop();
            }
            // ��������������� ������������ ����
            while (!tempStack.empty()) {
                ticketStack.push(tempStack.top());
                tempStack.pop();
            }
            if (!found) {
                cout << "������ � ����� ������� ����� � ����� ������ �� �������." << endl;
            }
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