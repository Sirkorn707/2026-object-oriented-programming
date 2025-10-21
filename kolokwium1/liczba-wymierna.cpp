#include <iostream>
using namespace std;

class LiczbaWymierna {
private:
    double licznik;
    double mianownik;

public:
    LiczbaWymierna(double l = 0, double m = 1) : licznik(l), mianownik(m) {
        if (mianownik == 0) {
            mianownik = 1;
        }
    }
    
    double getLicznik() const { return licznik; }
    double getMianownik() const { return mianownik; }
    
    void setLicznik(double l) { licznik = l; }
    void setMianownik(double m) { 
        if (m != 0) {
            mianownik = m;
        }
    }
    
    void print_info() const {
        cout << licznik << "/" << mianownik;
    }
};

int main()
{
    LiczbaWymierna liczba1(3, 4);
    LiczbaWymierna liczba2(5, 0); // Mianownik 0, powinien zostać ustawiony na 1

    cout << "Liczba 1: ";
    liczba1.print_info();
    cout << endl;

    cout << "Liczba 2: ";
    liczba2.print_info();
    cout << endl;

    return 0;
}