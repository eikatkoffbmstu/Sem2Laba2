#include <iostream>
#include <fstream> 
using namespace std;

class Vector {
    double* p = nullptr; // Указатель на массив значений вектора
    int n = 0; // Размер вектора

public:
    Vector(double* p, int n) { // Конструктор для создания вектора из массива значений
        this->n = n; 
        this->p = new double[n]; 
        for (int i = 0; i < n; i++) this->p[i] = p[i]; 
    }

    Vector(int n) : n(n) { // Конструктор для создания пустого вектора заданного размера
        p = new double[n]; 
    }

    Vector(const Vector& V) { 
        n = V.n; 
        p = new double[n]; 
        for (int i = 0; i < n; i++) 
            p[i] = V.p[i];
    }

    Vector(Vector&& V) { 
        std::swap(p, V.p); 
        std::swap(n, V.n); 
    }

    void print() const { // Метод для вывода значений вектора
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << endl;
    }

    double& operator[](int index) { // Перегруженный оператор индексации
        return p[index];
    }

    Vector& operator =(const Vector& v2) { // Перегруженный оператор присваивания с копированием
        if (this != &v2) { // Проверка, чтобы не было исключений
            n = v2.n;
            if (p != nullptr) delete[] p; 
            p = new double[n]; 
            for (int i = 0; i < n; i++) 
                p[i] = v2.p[i];
        }
        return *this;
    }

    Vector& operator =(Vector&& v2) { // Перегруженный оператор присваивания с перемещением
        if (this != &v2) { // Проверка, чтобы вызвалось без исключений
            std::swap(p, v2.p); 
            std::swap(n, v2.n); 
        }
        return *this;
    }

    Vector operator*(double x) { // Перегруженный оператор умножения на скаляр
        Vector result(n); /
        for (int i = 0; i < n; i++) // Умножение каждого элемента на скаляр
            result.p[i] = p[i] * x;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Vector& v) { // Перегруженный оператор вывода в поток
        for (int i = 0; i < v.n; i++) // Вывод значений вектора через поток вывода
            os << v.p[i] << " ";
        return os; 
    }

    friend istream& operator>>(istream& is, Vector& v) { // Перегруженный оператор ввода из потока
        for (int i = 0; i < v.n; i++) // Считывание значений вектора из потока ввода
            is >> v.p[i];
        return is; 
    }

    ~Vector() { // Деструктор класса
        delete[] p; 
    }
};

int main() {
    ifstream inputFile("input.txt");
    int size;
    inputFile >> size;
    double* values = new double[size];
    for (int i = 0; i < size; ++i) { 
        inputFile >> values[i]; 
    }
    inputFile >> scalar
    Vector V1(values, size); 
    cout << V1 << endl;
    Vector V2 = V1 * scalar
    cout << V2;
    return 0; 
}

