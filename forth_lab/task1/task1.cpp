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

    // ��������� ����������� ����� ��� ��������� ���������� ������������� ��������
    virtual void changeParameters() = 0;
};

class CPlane : public CVehicle {
private:
    double altitude;
    int passengers;

public:
    CPlane(double p, double s, int y, double x, double y_val, double a, int pass) : CVehicle(p, s, y, x, y_val), altitude(a), passengers(pass) {}

    void printInfo() const override {
        cout << "���: �������" << endl;
        cout << "����������: (" << getX() << ", " << getY() << ")" << endl;
        cout << "����: " << getPrice() << " ���." << endl;
        cout << "��������: " << getSpeed() << " ��/�" << endl;
        cout << "��� �������: " << getYear() << endl;
        cout << "������: " << altitude << " �" << endl;
        cout << "���������� ����������: " << passengers << endl;
    }

    string getType() const override {
        return "�������";
    }

    // ���������� ������ ��� ��������� ���������� ��������
    void changeParameters() override {
        cout << "������� ����� ����, ��������, ��� �������, ������ � ���������� ����������: ";
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
        cout << "���: ����������" << endl;
        cout << "����������: (" << getX() << ", " << getY() << ")" << endl;
        cout << "����: " << getPrice() << " ���." << endl;
        cout << "��������: " << getSpeed() << " ��/�" << endl;
        cout << "��� �������: " << getYear() << endl;
        cout << "���������� ����������: " << passengers << endl;
    }

    string getType() const override {
        return "����������";
    }

    // ���������� ������ ��� ��������� ���������� ����������
    void changeParameters() override {
        cout << "������� ����� ����, ��������, ��� ������� � ���������� ����������: ";
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
        cout << "���: �������" << endl;
        cout << "����������: (" << getX() << ", " << getY() << ")" << endl;
        cout << "����: " << getPrice() << " ���." << endl;
        cout << "��������: " << getSpeed() << " ��/�" << endl;
        cout << "��� �������: " << getYear() << endl;
        cout << "���������� ����������: " << passengers << endl;
        cout << "���� ��������: " << port << endl;
    }

    string getType() const override {
        return "�������";
    }

    // ���������� ������ ��� ��������� ���������� �������
    void changeParameters() override {
        cout << "������� ����� ����, ��������, ��� �������, ���������� ���������� � ���� ��������: ";
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

    // ������� ������� ������ ������� � ��������� �� � ������
    vehicles.push_back(new CPlane(10000000, 900, 2020, 10, 20, 10000, 300));
    vehicles.push_back(new CCar(500000, 150, 2018, 30, 40, 5));
    vehicles.push_back(new CShip(20000000, 50, 2015, 50, 60, 500, "Rotterdam"));

    // ���� ��� �������� ������� �������
    int choice;
    do {
        cout << "\n����:" << endl;
        cout << "1. ������� ���������� � ���� ������������ ���������" << endl;
        cout << "2. ������� ���������� � ���������� ������������ ��������" << endl;
        cout << "3. �������� ��������� ������������� ��������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n���������� � ������������ ���������:" << endl;
            for (const auto& vehicle : vehicles) {
                vehicle->printInfo();
                cout << endl;
            }
            break;
        case 2:
            int index;
            cout << "������� ������ ������������� ��������: ";
            cin >> index;
            if (index >= 0 && index < vehicles.size()) {
                vehicles[index]->printInfo();
            }
            else {
                cout << "�������� ������." << endl;
            }
            break;
        case 3:
            int vehicleIndex;
            cout << "������� ������ ������������� ��������, ��������� �������� ����� ��������: ";
            cin >> vehicleIndex;
            if (vehicleIndex >= 0 && vehicleIndex < vehicles.size()) {
                vehicles[vehicleIndex]->changeParameters();
            }
            else {
                cout << "�������� ������." << endl;
            }
            break;
        case 0:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� �����. ��������� �������." << endl;
            break;
        }
    } while (choice != 0);

    // ������� ���������� ������
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}