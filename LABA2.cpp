#include <iostream>
using namespace std;

class Vector {
    double* p = nullptr;
    int n = 0;

public:
    Vector(double* p, int n) {
        this->n = n;
        this->p = new double[n];
        for (int i = 0; i < n; i++) this->p[i] = p[i];
    }

    Vector(int n) : n(n) {
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

    void print() const {
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << endl;
    }

    double& operator[](int index) {
        return p[index];
    }

    Vector& operator =(const Vector& v2) {
        if (this != &v2) {
            n = v2.n;
            if (p != nullptr) delete[] p;
            p = new double[n];
            for (int i = 0; i < n; i++) p[i] = v2.p[i];
        }
        return *this;
    }

    Vector& operator =(Vector&& v2) {
        if (this != &v2) {
            std::swap(p, v2.p);
            std::swap(n, v2.n);
        }
        return *this;
    }

    Vector operator*(double x) {
        Vector result(n);
        for (int i = 0; i < n; i++) result.p[i] = p[i] * x;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Vector& v) {
        for (int i = 0; i < v.n; i++)
            os << v.p[i] << " ";
        return os;
    }

    friend istream& operator>>(istream& is, Vector& v) {
        for (int i = 0; i < v.n; i++)
            is >> v.p[i];
        return is;
    }

    ~Vector() {
        if (p != nullptr) delete[] p;
    }
};

int main() {
    double m1[] = { 1, 2, 3, 4.5, 7 };
    Vector V1(m1, 5);
    Vector V2 = V1 * 2;
    cout << V2 << endl; 
    Vector V3(5);
    cin >> V3; 
    V3.print(); 
    return 0;
}
