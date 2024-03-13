#include <iostream>
using namespace std;

class Vector {
    double* p = nullptr; // Указатель на массив значений вектора
    int n = 0; // Размерность вектора

public:
    // Конструктор, создающий вектор из массива значений
    Vector(double* p, int n) {
        this->n = n;
        this->p = new double[n]; // Выделение памяти для массива значений вектора
        for (int i = 0; i < n; i++) this->p[i] = p[i]; // Копирование значений из массива
    }

    // Конструктор, создающий вектор определенной размерности без инициализации
    Vector(int n) : n(n) {
        p = new double[n]; // Выделение памяти для массива значений вектора
    }

    // Конструктор копирования
    Vector(const Vector& V) {
        n = V.n;
        p = new double[n]; // Выделение памяти для массива значений вектора
        for (int i = 0; i < n; i++)
            p[i] = V.p[i]; // Копирование значений из другого вектора
    }

    // Конструктор перемещения
    Vector(Vector&& V) {
        std::swap(p, V.p); // Обмен указателями на массивы значений векторов
        std::swap(n, V.n); // Обмен размерностями векторов
    }

    // Метод для вывода вектора
    void print() const {
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << endl;
    }

    // Оператор доступа к элементам вектора
    double& operator[](int index) {
        return p[index];
    }

    // Оператор присваивания для копирования
    Vector& operator =(const Vector& v2) {
        if (this != &v2) {
            n = v2.n;
            if (p != nullptr) delete[] p; // Освобождение памяти
            p = new double[n]; // Выделение новой памяти
            for (int i = 0; i < n; i++) p[i] = v2.p[i]; // Копирование значений
        }
        return *this;
    }

    // Оператор присваивания для перемещения
    Vector& operator =(Vector&& v2) {
        if (this != &v2) {
            std::swap(p, v2.p); // Обмен указателями на массивы значений
            std::swap(n, v2.n); // Обмен размерностями векторов
        }
        return *this;
    }

    // Оператор умножения вектора на скаляр
    Vector operator*(double x) {
        Vector result(n); // Создание нового вектора
        for (int i = 0; i < n; i++) result.p[i] = p[i] * x; // Умножение каждого элемента на скаляр
        return result; // Возврат нового вектора
    }

    // Метод для вывода вектора в поток
    void output(ostream& os) const {
        for (int i = 0; i < n; i++)
            os << p[i] << " ";
    }

    // Метод для ввода вектора из потока
    void input(istream& is) {
        for (int i = 0; i < n; i++)
            is >> p[i];
    }

    // Деструктор
    ~Vector() {
        if (p != nullptr) delete[] p; // Освобождение памяти
    }
};

// Перегрузка оператора << для вывода вектора в поток
ostream& operator<<(ostream& os, const Vector& v) {
    v.output(os); // Вызов метода вывода
    return os;
}

// Перегрузка оператора >> для ввода вектора из потока
istream& operator>>(istream& is, Vector& v) {
    v.input(is); // Вызов метода ввода
    return is;
}

int main() {
    double m1[] = { 1, 2, 3, 4.5, 7 };
    Vector V1(m1, 5); // Создание вектора с указанными значениями
    Vector V2 = V1 * 2; // Умножение вектора на скаляр
    cout << V2 << endl; // Печать V2
    Vector V3(5);
    cin >> V3; // Ввод данных в V3
    V3.print(); // Печать V3
    return 0;
}
