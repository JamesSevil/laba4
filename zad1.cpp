// 2𝑥 + 𝑡𝑔(𝑥) = 0
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// Метод Ньютона
double f(double x) { // значение функции
    return 2*x + tan(x);
}
double fsh(double x) { // значение производой функции
    return 2 + 1/(cos(x)*cos(x));
}
double newton(double x0, double eps) {
    double x1 = x0 - f(x0) / fsh(x0);
    int iternum = 1;

    while (fabs(x1 - x0) > eps) {
        cout << iternum << setw(15) << x0 << setw(15) << x1 << setw(15) << x1 - x0 << endl;
        x0 = x1;
        x1 = x0 - f(x0) / fsh(x0);
        iternum++;
    }
    return x0;
}

// Метод простых итераций
double phi(double x) { // итерационная функция
    return x - f(x) / fsh(x);
}
double SimpleIterations(double x0, double eps) {
    double x1 = phi(x0);
    int iternum = 1;
    while (fabs(x1 - x0) > eps) {
        cout << iternum << setw(15) << x0 << setw(15) << x1 << setw(15) << x1 - x0 << endl;
        x0 = x1;
        x1 = phi(x0);
        iternum++;
    }
    return x0;
}

// Метод половинного деления
double bisection(double a, double b, double eps) {
    double c = 0.0;
    int iternum = 1;
    while (fabs(b - a) > eps) {
        cout << iternum << setw(15) << a << setw(15) << b << setw(15) << b - a << endl;
        c = (a + b) / 2;
        if (f(c) == 0.0) {
            break;
        } else if (f(c) * f(a) < 0){
            b = c;
        } else {
            a = c;
        }
        iternum++;
    }
    return c;
}


int main() {
    setlocale(LC_ALL, "Rus");
    // Метод Ньютона
    cout << "Метод Ньютона:" << endl << "N" << setw(15) << "xn" << setw(15) << "xn+1" << setw(15) << "xn+1 - xn" << endl;
    double x0 = 1.5; // начальное приближение
    double eps = 0.0001; // точность решения
    double x = newton(x0, eps);
    cout << "Корень: " << x << endl << endl;

    // Метод простых итераций
    cout << "Метод простых итераций:" << endl << "N" << setw(15) << "xn" << setw(15) << "xn+1" << setw(15) << "xn+1 - xn" << endl;
    x0 = 1.5; // начальное приближение
    eps = 0.0001; // точность решение
    x = SimpleIterations(x0, eps);
    cout << "Корень: " << x << endl << endl;

    // Метод половинного деления
     cout << "Метод половинного деления:" << endl << "N" << setw(15) << "an" << setw(15) << "bn" << setw(15) << "bn - an" << endl;
    double a = -10.0; // начальный интервал
    double b = 5.0;
    eps = 0.0001; // точность решения
    x = bisection(a, b, eps);
    cout << "Корень: " << x << endl << endl;

    return 0;
}