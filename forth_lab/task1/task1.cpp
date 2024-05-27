#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CVehicle {
protected:
    double price;
    double speed;
    int year;
    double x;
    double y;

public:
    CVehicle(double p, double s, int y, double x_val, double y_val) : price(p), speed(s), year(y), x(x_val), y(y_val) {}

    virtual ~CVehicle() {}

    void setCoordinates(double new_x, double new_y) {
        x = new_x;
        y = new_y;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    void setParameters(double p, double s, int y) {
        price = p;
        speed = s;
        year = y;
    }

    double getPrice() const {
        return price;
    }

    double getSpeed() const {
        return speed;
    }

    int getYear() const {
        return year;
    }

    virtual void printInfo() const = 0;
    virtual string getType() const = 0;

    // Добавляем виртуальный метод для изменения параметров транспортного средства
    virtual void changeParameters() = 0;
};

class CPlane : public CVehicle {
private:
    double altitude;
    int passengers;

public:
    CPlane(double p, double s, int y, double x, double y_val, double a, int pass) : CVehicle(p, s, y, x, y_val), altitude(a), passengers(pass) {}

    void printInfo() const override {
        cout << "Тип: Самолет" << endl;
        cout << "Координаты: (" << getX() << ", " << getY() << ")" << endl;
        cout << "Цена: " << getPrice() << " руб." << endl;
        cout << "Скорость: " << getSpeed() << " км/ч" << endl;
        cout << "Год выпуска: " << getYear() << endl;
        cout << "Высота: " << altitude << " м" << endl;
        cout << "Количество пассажиров: " << passengers << endl;
    }

    string getType() const override {
        return "Самолет";
    }

    // Реализация метода для изменения параметров самолета
    void changeParameters() override {
        cout << "Введите новую цену, скорость, год выпуска, высоту и количество пассажиров: ";
        double new_price, new_speed, new_altitude;
        int new_year, new_passengers;
        cin >> new_price >> new_speed >> new_year >> new_altitude >> new_passengers;
        setParameters(new_price, new_speed, new_year);
        altitude = new_altitude;
        passengers = new_passengers;
    }
};

class CCar : public CVehicle {
private:
    int passengers;

public:
    CCar(double p, double s, int y, double x, double y_val, int pass) : CVehicle(p, s, y, x, y_val), passengers(pass) {}

    void printInfo() const override {
        cout << "Тип: Автомобиль" << endl;
        cout << "Координаты: (" << getX() << ", " << getY() << ")" << endl;
        cout << "Цена: " << getPrice() << " руб." << endl;
        cout << "Скорость: " << getSpeed() << " км/ч" << endl;
        cout << "Год выпуска: " << getYear() << endl;
        cout << "Количество пассажиров: " << passengers << endl;
    }

    string getType() const override {
        return "Автомобиль";
    }

    // Реализация метода для изменения параметров автомобиля
    void changeParameters() override {
        cout << "Введите новую цену, скорость, год выпуска и количество пассажиров: ";
        double new_price, new_speed;
        int new_year, new_passengers;
        cin >> new_price >> new_speed >> new_year >> new_passengers;
        setParameters(new_price, new_speed, new_year);
        passengers = new_passengers;
    }
};

class CShip : public CVehicle {
private:
    int passengers;
    string port;

public:
    CShip(double p, double s, int y, double x, double y_val, int pass, const string& prt) : CVehicle(p, s, y, x, y_val), passengers(pass), port(prt) {}

    void printInfo() const override {
        cout << "Тип: Корабль" << endl;
        cout << "Координаты: (" << getX() << ", " << getY() << ")" << endl;
        cout << "Цена: " << getPrice() << " руб." << endl;
        cout << "Скорость: " << getSpeed() << " км/ч" << endl;
        cout << "Год выпуска: " << getYear() << endl;
        cout << "Количество пассажиров: " << passengers << endl;
        cout << "Порт приписки: " << port << endl;
    }

    string getType() const override {
        return "Корабль";
    }

    // Реализация метода для изменения параметров корабля
    void changeParameters() override {
        cout << "Введите новую цену, скорость, год выпуска, количество пассажиров и порт приписки: ";
        double new_price, new_speed;
        int new_year, new_passengers;
        string new_port;
        cin >> new_price >> new_speed >> new_year >> new_passengers >> new_port;
        setParameters(new_price, new_speed, new_year);
        passengers = new_passengers;
        port = new_port;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    vector<CVehicle*> vehicles;

    // Создаем объекты разных классов и добавляем их в вектор
    vehicles.push_back(new CPlane(10000000, 900, 2020, 10, 20, 10000, 300));
    vehicles.push_back(new CCar(500000, 150, 2018, 30, 40, 5));
    vehicles.push_back(new CShip(20000000, 50, 2015, 50, 60, 500, "Rotterdam"));

    // Меню для проверки методов классов
    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Вывести информацию о всех транспортных средствах" << endl;
        cout << "2. Вывести информацию о конкретном транспортном средстве" << endl;
        cout << "3. Изменить параметры транспортного средства" << endl;
        cout << "0. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nИнформация о транспортных средствах:" << endl;
            for (const auto& vehicle : vehicles) {
                vehicle->printInfo();
                cout << endl;
            }
            break;
        case 2:
            int index;
            cout << "Введите индекс транспортного средства: ";
            cin >> index;
            if (index >= 0 && index < vehicles.size()) {
                vehicles[index]->printInfo();
            }
            else {
                cout << "Неверный индекс." << endl;
            }
            break;
        case 3:
            int vehicleIndex;
            cout << "Введите индекс транспортного средства, параметры которого нужно изменить: ";
            cin >> vehicleIndex;
            if (vehicleIndex >= 0 && vehicleIndex < vehicles.size()) {
                vehicles[vehicleIndex]->changeParameters();
            }
            else {
                cout << "Неверный индекс." << endl;
            }
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Повторите попытку." << endl;
            break;
        }
    } while (choice != 0);

    // Очищаем выделенную память
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
