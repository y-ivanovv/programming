#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Product {
private:
    double price; // ���� ������
    int quantity; // ���������� ������ ������

public:
    // ����������� ��� ������������� �������
    Product(double p = 0.0, int q = 0) : price(p), quantity(q) {}

    // ������� ������������ ������ � ����������� �� �������
    string getInfo() const {
        stringstream ss;
        ss << "���� ������: " << price << " ���." << "\n";
        ss << "���������� ������ ������: " << quantity;
        return ss.str();
    }

    // ������� ���������� ����� ��������� ������
    double getTotalPrice() const {
        return price * quantity;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    // ������� ������ ������ Product ����� ���������
    Product* productPtr = new Product();

    // ������ �������� ���� � ���������� ������
    double price;
    int quantity;
    cout << "������� ���� ������: ";
    cin >> price;
    cout << "������� ���������� ������ ������: ";
    cin >> quantity;

    // �������������� ������ ����� ���������
    *productPtr = Product(price, quantity);

    // ������� ���������� � ������
    cout << productPtr->getInfo() << endl;

    // ��������� ����� ��������� ������ � ������� �
    double totalPrice = productPtr->getTotalPrice();
    cout << "����� ��������� ������: " << totalPrice << " ���." << endl;

    // ������� ������, ��������� ����� ���������
    delete productPtr;

    return 0;
}
