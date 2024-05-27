#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data; // std::vector как серверный класс

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
};

void displayMenu() {
    cout << "\nМеню:" << endl;
    cout << "1. Добавить элемент в стек" << endl;
    cout << "2. Удалить элемент из стека" << endl;
    cout << "3. Показать верхний элемент стека" << endl;
    cout << "4. Проверить, пуст ли стек" << endl;
    cout << "5. Показать размер стека" << endl;
    cout << "0. Выйти" << endl;
    cout << "Выберите действие: ";
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
            cout << "Введите значение для добавления в стек: ";
            cin >> value;
            intStack.push(value);
            cout << "Значение добавлено в стек." << endl;
            break;
        }
        case 2: {
            try {
                intStack.pop();
                cout << "Верхний элемент удален из стека." << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            try {
                cout << "Верхний элемент стека: " << intStack.top() << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            if (intStack.empty()) {
                cout << "Стек пуст." << endl;
            }
            else {
                cout << "Стек не пуст." << endl;
            }
            break;
        }
        case 5: {
            cout << "Размер стека: " << intStack.size() << endl;
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