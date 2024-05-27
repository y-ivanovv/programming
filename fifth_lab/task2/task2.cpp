#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data; // std::vector для хранения элементов стека

public:
    // Добавление элемента в стек
    void push(const T& value) {
        data.push_back(value);
    }

    // Удаление элемента из стека
    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
        else {
            cout << "Стек пуст. Невозможно удалить элемент." << endl;
        }
    }

    // Получение верхнего элемента стека
    T top() const {
        if (!data.empty()) {
            return data.back();
        }
        else {
            throw out_of_range("Стек пуст. Нет верхнего элемента.");
        }
    }

    // Проверка, пуст ли стек
    bool empty() const {
        return data.empty();
    }

    // Получение размера стека
    size_t size() const {
        return data.size();
    }

    // Вывод всех элементов стека
    void printAll() const {
        for (const auto& item : data) {
            cout << item << endl;
        }
    }
};

// Структура для хранения заявки
struct TicketRequest {
    string destination;
    string flightNumber;
    string passengerName;
    string departureDate;

    // Перегрузка оператора вывода для удобного отображения заявки
    friend ostream& operator<<(ostream& os, const TicketRequest& request) {
        os << "Пункт назначения: " << request.destination << endl;
        os << "Номер рейса: " << request.flightNumber << endl;
        os << "Пассажир: " << request.passengerName << endl;
        os << "Дата вылета: " << request.departureDate << endl;
        return os;
    }
};

void displayMenu() {
    cout << "\nМеню:" << endl;
    cout << "1. Добавить заявку" << endl;
    cout << "2. Удалить последнюю заявку" << endl;
    cout << "3. Показать последнюю заявку" << endl;
    cout << "4. Показать все заявки" << endl;
    cout << "5. Найти заявки по номеру рейса и дате вылета" << endl;
    cout << "0. Выйти" << endl;
    cout << "Выберите действие: ";
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
            cout << "Введите пункт назначения: ";
            cin >> ws; // Игнорировать пробелы перед вводом строки
            getline(cin, request.destination);
            cout << "Введите номер рейса: ";
            getline(cin, request.flightNumber);
            cout << "Введите фамилию и инициалы пассажира: ";
            getline(cin, request.passengerName);
            cout << "Введите желаемую дату вылета (дд.мм.гггг): ";
            getline(cin, request.departureDate);
            ticketStack.push(request);
            cout << "Заявка добавлена." << endl;
            break;
        }
        case 2: {
            try {
                ticketStack.pop();
                cout << "Последняя заявка удалена." << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            try {
                cout << "Последняя заявка:" << endl;
                cout << ticketStack.top() << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            cout << "Все заявки:" << endl;
            ticketStack.printAll();
            break;
        }
        case 5: {
            string flightNumber, departureDate;
            cout << "Введите номер рейса: ";
            cin >> ws;
            getline(cin, flightNumber);
            cout << "Введите дату вылета (дд.мм.гггг): ";
            getline(cin, departureDate);
            cout << "Заявки с номером рейса " << flightNumber << " и датой вылета " << departureDate << ":" << endl;
            Stack<TicketRequest> tempStack; // Временный стек для поиска
            bool found = false;
            while (!ticketStack.empty()) {
                if (ticketStack.top().flightNumber == flightNumber && ticketStack.top().departureDate == departureDate) {
                    cout << ticketStack.top() << endl;
                    found = true;
                }
                tempStack.push(ticketStack.top());
                ticketStack.pop();
            }
            // Восстанавливаем оригинальный стек
            while (!tempStack.empty()) {
                ticketStack.push(tempStack.top());
                tempStack.pop();
            }
            if (!found) {
                cout << "Заявок с таким номером рейса и датой вылета не найдено." << endl;
            }
            break;
        }
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