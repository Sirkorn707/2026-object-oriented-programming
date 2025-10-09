// Zadanie 1. 
// Stwórz klasę o nazwie Point2D reprezentującą punkt na płaszczyźnie. Klasa powinna posiadać:
// a. pola reprezentujące współrzędne punktu,
// b. parametryczny konstruktor z przypisanymi wartościami domyślnymi argumentów,
// c. konstruktor kopiujący,
// d. gettery i settery dla współrzędnych punktu.

// Zadanie 2.
// Stwórz klasę o nazwie Circle reprezentującą okrąg na płaszczyźnie. Klasa powinna posiadać:
// a. pola reprezentujące położenie okręgu oraz jego promień,
// b. parametryczny konstruktor z przypisanymi wartościami domyślnymi argumentów,
// c. metodę bool is_inside(const Point2D& p), która zwraca wartość true, gdy punkt p
// znajduje się wewnątrz tego okręgu, oraz false w przeciwnym wypadku.
#include <iostream>
#include <random>
#include <chrono>

class Point2D
{
public:
    double x;
    double y;

    Point2D() : x(0.0), y(0.0) {}
    Point2D(double x_val, double y_val) : x(x_val), y(y_val) {}
    Point2D(const Point2D& other) : x(other.x), y(other.y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double x_val) { x = x_val; }
    void setY(double y_val) { y = y_val; }
};

class Circle
{
public:
    Point2D center;
    double radius;

    Circle() : center(Point2D()), radius(1.0) {}
    Circle(Point2D c, double r) : center(c), radius(r) {}

    // Funkcja ktora sprawdza czy punkt p znajduje sie wewnatrz okregu
    bool is_inside(const Point2D& p) const
    {
        double x_ = p.getX() - center.getX();
        double y_ = p.getY() - center.getY();
        return (x_ * x_ + y_ * y_) < (radius * radius);
    }
};

int main()
{
    Point2D p1;
    Point2D p2(1.0, 2.0);
    Point2D p3 = p2;

    p1.setX(1.0);
    p1.setY(1.0);
    std::cout << "P1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "P2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    std::cout << "P3: (" << p3.getX() << ", " << p3.getY() << ")" << std::endl;

    Circle c1(Point2D(0.0, 0.0), 2.0);
    std::cout << "Czy p1 znajduje sie w okregu c1? " << (c1.is_inside(p1) ? "Tak" : "Nie") << std::endl;
    

    // metoda monte carlo -> mamy obliczyc liczbe pi
    const int N = 1000000; // liczba prób
    int w_kole = 0; // ilosc punktow w kole

    Circle c(Point2D(0.0, 0.0), 1.0);

    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    for (int i = 0; i < N; ++i) 
    {
        double x = distribution(gen); // losujemy wspolrzedne z rozkl. rownomiernego 
        double y = distribution(gen);
        Point2D p(x, y);
        if (c.is_inside(p)) {
            ++w_kole;
        }
    }

    double pi_moje = 4.0 * w_kole / N; // 4/pi = n_w_kole/N
    std::cout << "Liczba punktow w kole: " << w_kole << std::endl;
    std::cout << "Liczba wszystkich punktow: " << N << std::endl;
    std::cout << "Przyblizenie liczby pi: " << pi_moje << std::endl;
    return 0;
}