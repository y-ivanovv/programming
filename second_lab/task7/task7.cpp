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
        throw runtime_error("Не удалось открыть файл для записи: " + filename);
    }

    for (const auto& product : products) {
        file.write(reinterpret_cast<const char*>(&product), sizeof(Product));
    }
    file.close();
}

Product readMostExpensiveProduct(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("Не удалось открыть файл для чтения: " + filename);
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

    // Создание и запись продуктов в файл
    vector<Product> products = {
        {"Картошка", 100.0, "руб"},
        {"Помидор", 150.0, "руб"},
        {"Хлеб", 200.0, "руб"},
        {"Йогурт", 175.0, "руб"},
    };

    writeProducts(filename, products);

    // Чтение самого дорогого продукта из файла
    Product mostExpensiveProduct = readMostExpensiveProduct(filename);

    // Вывод информации о самом дорогом продукте
    cout << "Самый дорогой товар:\n";
    cout << "Наименование: " << mostExpensiveProduct.name << '\n';
    cout << "Стоимость: " << mostExpensiveProduct.price << '\n';
    cout << "Единица измерения: " << mostExpensiveProduct.unit << '\n';

    return 0;
}