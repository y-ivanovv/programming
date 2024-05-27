#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Product {
    char name[50];
    double price;
    char unit[20];
};

void writeProducts(const string& filename, const vector<Product>& products) {
    ofstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("�� ������� ������� ���� ��� ������: " + filename);
    }

    for (const auto& product : products) {
        file.write(reinterpret_cast<const char*>(&product), sizeof(Product));
    }
    file.close();
}

Product readMostExpensiveProduct(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("�� ������� ������� ���� ��� ������: " + filename);
    }

    Product mostExpensiveProduct;
    mostExpensiveProduct.price = numeric_limits<double>::lowest();
    Product currentProduct;

    while (file.read(reinterpret_cast<char*>(&currentProduct), sizeof(Product))) {
        if (currentProduct.price > mostExpensiveProduct.price) {
            mostExpensiveProduct = currentProduct;
        }
    }
    file.close();

    return mostExpensiveProduct;
}

int main() {
    setlocale(LC_ALL, "ru");
    string filename = "products.dat";

    // �������� � ������ ��������� � ����
    vector<Product> products = {
        {"��������", 100.0, "���"},
        {"�������", 150.0, "���"},
        {"����", 200.0, "���"},
        {"������", 175.0, "���"},
    };

    writeProducts(filename, products);

    // ������ ������ �������� �������� �� �����
    Product mostExpensiveProduct = readMostExpensiveProduct(filename);

    // ����� ���������� � ����� ������� ��������
    cout << "����� ������� �����:\n";
    cout << "������������: " << mostExpensiveProduct.name << '\n';
    cout << "���������: " << mostExpensiveProduct.price << '\n';
    cout << "������� ���������: " << mostExpensiveProduct.unit << '\n';

    return 0;
}