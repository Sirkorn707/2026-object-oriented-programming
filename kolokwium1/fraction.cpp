#include <iostream>

using namespace std;

class Fraction 
{
private:
    int m_num;
    int m_den;
public:
    Fraction(int numerator=0, int denominator=0) : m_num(numerator), m_den(denominator){}
    
    int get_num(void) const {return m_num;}
    int get_den(void) const {return m_den;}

    void set_num(int num) {m_num = num;}
    void set_den(int den) {m_den = den;}

    int Dodawanie(const Fraction &f)
    {
        return (m_num * f.m_den) + (f.m_num * m_den);
    }

    int Postinkrementacja()
    {
        return m_num++;
    }

    int Wyjscie()
    {
        cout << m_num << "/" << m_den << endl;
        return 0;
    }
};

int main()
{
    Fraction f1(3,4);
    Fraction f2(2,5);

    cout << "Wartosc licznika f1: " << f1.get_num() << endl;
    cout << "Wartosc mianownika f1: " << f1.get_den() <<  endl;

    f1.set_num(5);
    f1.set_den(8);

    cout << "Po zmianie wartosci:" << endl;
    cout << "Wartosc licznika f1: " << f1.get_num() << endl;
    cout << "Wartosc mianownika f1: " << f1.get_den() <<  endl;

    int suma = f1.Dodawanie(f2);
    cout << "Suma ulamkow f1 i f2 (licznik): " << suma << endl;

    cout << "Postinkrementacja licznika f1: " << f1.Postinkrementacja() << endl;
    cout << "Wartosc licznika f1 po postinkrementacji: " << f1.get_num() << endl;

    cout << "Wyswietlenie ulamka f1: ";
    f1.Wyjscie();

    return 0;
}