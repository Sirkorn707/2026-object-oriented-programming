/*
Zadanie 4.
Napisz program, który implementuje za pomocą funkcji rekurencyjnej algorytm bisekcji a nastepnie
wyznaczy pierwiastek równania 3x^2+7x+1=0 w przedziale [-1.0; 1.0].
*/
#include <iostream>
#include <cmath>

double funkcja(double x) {
    double pow(double podstawa, double wykladnik);
    return 3 * pow(x, 2) + 7 * x + 1;
}

double bisekcja(double a, double b, double eps) {
    double c = (a + b) / 2;
    if (fabs(funkcja(c)) < eps) {
        return c;
    }
    if (funkcja(a) * funkcja(c) < 0) {
        return bisekcja(a, c, eps);
    }
    return bisekcja(c, b, eps);
}
int main() {
    double a = -1.0;
    double b = 1.0;
    double eps = 1e-6;

    double pierwiastek = bisekcja(a, b, eps);
    std::cout << "Pierwiastek rownania 3x^2 + 7x + 1 = 0 w przedziale [" << a << ", " << b << "] to: " << pierwiastek << std::endl;

    return 0;
}