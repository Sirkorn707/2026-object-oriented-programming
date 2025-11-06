/*
Zadanie 2.
Napisz definicję klasy, która reprezentuje liczbę zespoloną. Klasa powinna posiadać: dwa pola
reprezentujące odpowiednio część rzeczywistą i urojoną liczby zespolonej. Konstruktor z dwoma
argumentami i przypisanymi im wartościami domyślnymi. Gettery i settery dla części rzeczywistej i
urojonej. Zaimplementuj następujące operatory: dodawanie, wejście i wyjście, przypisanie i
porównanie, pre oraz post inkrementacji. W funkcji main() utwórz dwa obiekty reprezentujące
liczby zespolone i wykonaj na nich działania za pomocą zdefiniowanych funkcji operatorowych.
Wypisz wynik na ekranie posługując się zdefiniowanym operatorem wyjścia.
*/

#include <iostream>

class liczbaZespolona
{
private:
    double Real;
    double Imag;
public:
    liczbaZespolona(double r = 0.0, double i = 0.0) : Real(r), Imag(i) {}

    double getReal() const { return Real; }
    double getImag() const { return Imag; }

    void setReal(double r) { Real = r; }
    void setImag(double i) { Imag = i; }

    //operator dodawania
    liczbaZespolona operator+(const liczbaZespolona& other) const
    {
        return liczbaZespolona(Real + other.Real, Imag + other.Imag);
    }

    // operator wejścia/wyjścia
    friend std::ostream& operator<<(std::ostream& os, const liczbaZespolona& z)
    {
        os << z.Real << " + " << z.Imag << "i";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, liczbaZespolona& z)
    {
        std::cout << "Podaj czesc rzeczywista: ";
        is >> z.Real;
        std::cout << "Podaj czesc urojona: ";
        is >> z.Imag;
        return is;
    }

    //operator przypisania
    liczbaZespolona& operator=(const liczbaZespolona& other)
    {
        if (this != &other)
        {
            Real = other.Real;
            Imag = other.Imag;
        }
        return *this;
    }

    //operator porównania
    bool operator==(const liczbaZespolona& other) const
    {
        return (Real == other.Real) && (Imag == other.Imag);
    }

    //operator pre-inkrementacji
    liczbaZespolona& operator++() 
    {
        ++Real;
        return *this;
    }

    //operator post-inkrementacji
    liczbaZespolona operator++(int) 
    {
        liczbaZespolona temp = *this;
        ++Real;
        return temp;
    }

};

int main() 
{
    liczbaZespolona z1(2, 2);
    liczbaZespolona z2(-1, 6);

    std::cout << "Z1: " << z1 << std::endl;
    std::cout << "Z2: " << z2 << std::endl;

    liczbaZespolona z3 = z1 + z2;
    std::cout << "Z1 + Z2: " << z3 << std::endl;

    return 0;
}