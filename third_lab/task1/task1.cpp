#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Product {
private:
    double price; // Цена товара
    int quantity; // Количество единиц товара

public:
    // Конструктор для инициализации объекта
    Product(double p = 0.0, int q = 0) : price(p), quantity(q) {}

    // Функция формирования строки с информацией об объекте
    string getInfo() const {
        stringstream ss;
        ss << "Цена товара: " << price << " руб." << "\n";
        ss << "Количество единиц товара: " << quantity;
        return ss.str();
    }

    // Функция вычисления общей стоимости товара
    double getTotalPrice() const {
        return price * quantity;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    // Создаем объект класса Product через указатель
    Product* productPtr = new Product();

    // Вводим значения цены и количества товара
    double price;
    int quantity;
    cout << "Введите цену товара: ";
    cin >> price;
    cout << "Введите количество единиц товара: ";
    cin >> quantity;

    // Инициализируем объект через указатель
    *productPtr = Product(price, quantity);

    // Выводим информацию о товаре
    cout << productPtr->getInfo() << endl;

    // Вычисляем общую стоимость товара и выводим её
    double totalPrice = productPtr->getTotalPrice();
    cout << "Общая стоимость товара: " << totalPrice << " руб." << endl;

    // Удаляем объект, созданный через указатель
    delete productPtr;

    return 0;
}
