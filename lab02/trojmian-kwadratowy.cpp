// Stwórz klasę o nazwie TQuadEq reprezentującą trójmian kwadratowy. Klasa powinna zawierać:
// a. pola reprezentująca współczynniki trójmianu
// b. Konstruktor domyślny oraz parametryczny
// c. Gettery oraz settery dla wszystkich pól klasy
// d. metodę double ComputeDelta(void) const zwracającą wartość delty trójmianu
// e. metodę int GetNumRoots(const double delta) const zwracającą liczbę pierwiastków
// rzeczywistych trójmianu
// f. metodę GetRoots(double& root1, double& root2) const zwracającą rzeczywiste
// pierwiastki trójmianu.
// g. W funkcji main() napisz prosty program demonstrujący wykorzystanie klasy TQuadEq. Program
// wczytuje z klawiatury współczynniki trójmianu a następnie wyświetla na ekranie jego pierwiastki.
#include <iostream>
#include <cmath>

class TQuadEq
{   
private:
    double a; // a
    double b;
    double c;
public:
    TQuadEq() : a(1.0), b(0.0), c(0.0) {} // b
    TQuadEq(double a, double b, double c) : a(a), b(b), c(c) {}
    
    double getA() const { return a; } // c
    double getB() const { return b; }
    double getC() const { return c; }
    void setA(double a_val) { a = a_val; }
    void setB(double b_val) { b = b_val; }
    void setC(double c_val) { c = c_val; }

    double ComputeDelta() const { return b * b - 4 * a * c; } // d
    int GetNumRoots(const double delta) const  // e
    {
        if (delta > 0) return 2;
        else if (delta == 0) return 1;
        else return 0;
    }
    void GetRoots(double& root1, double& root2) const // f
    {
        double delta = ComputeDelta();
        if (delta < 0)
        {
            std::cout << "Brak pierwiastkow rzeczywistych." << std::endl;
            return; 
        }
        root1 = (-b + sqrt(delta)) / (2 * a);
        root2 = (-b - sqrt(delta)) / (2 * a);
    }
};

// g
int main() 
{
    double a, b, c;
    std::cout << "Podaj wspolczynniki a, b, c trojmianu kwadratowego: ";
    std::cin >> a >> b >> c;
    TQuadEq equation(a, b, c);
    double root1, root2;
    equation.GetRoots(root1, root2);
    std::cout << "Pierwiastki: " << root1 << ", " << root2 << std::endl;
    return 0;
}