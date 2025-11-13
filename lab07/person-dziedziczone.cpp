/*
Zadanie 1.
ad 1) klasa Person, reprezentuje osobę. Zawiera: imię, nazwisko, pesel, konstruktor parametryczny, gettery
metoda string to string która zwróci reprezentację obiektu jako string
*/

#include <iostream>
#include <string>
#include <vector>

class Person 
{
private:
    std::string imie;
    std::string nazwisko;
    std::string pesel;
public:
    Person(std::string imie = "Jan", std::string nazwisko = "Kowalski", std::string pesel = "200001016969") 
    {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->pesel = pesel;
    }
    std::string getImie () const {return imie;}
    std::string getNazwisko () const {return nazwisko;}
    std::string getPesel () const {return pesel;}

    virtual std::string to_string() const
    {
        return "Imie: " + imie + ", Nazwisko: " + nazwisko + ", PESEL: " + pesel;
    }
};

class Student : public Person 
{
public:
    std::string numer_indeksu;
    std::string kierunek_studiow;

    Student(std::string imie = "Jan", std::string nazwisko = "Kowalski", std::string pesel = "200001016969", std::string numer_indeksu = "", std::string kierunek_studiow = "")
        : Person(imie, nazwisko, pesel), numer_indeksu(numer_indeksu), kierunek_studiow(kierunek_studiow) {}
    
    std::string to_string() const override 
    {
        return Person::to_string() + ", Nr indeksu: " + numer_indeksu + ", Kierunek: " + kierunek_studiow;
    }
};

std::ostream& operator<<(std::ostream& os, const Student& s) 
{
    os << s.to_string();
    return os;
}

int main() 
{
    Person p1;

    std::vector<Person> osoby; // zad 4.
    Person p2("Artur", "Rizzmaster", "200501021420");
    Student s("Waldemar", "Brzeczek", "200001012000", "400000", "Elektronika");

    osoby.push_back(p2);
    osoby.push_back(s);

    for (const auto &osoba : osoby) std::cout << osoba.to_string() << std::endl;

    std::vector<Person*> wskazniki; // zad 5.

    Person p3("Adam", "Nawalka", "2005010121441");
    Student s2("Ola", "Miroslaw", "200000000000", "400000", "Matematyka");

    wskazniki.push_back(&p3);
    wskazniki.push_back(&s2);

    for (const auto &wsk : wskazniki) std::cout << wsk->to_string() << std::endl;

    //std::cout << p1.to_string() << std::endl;
    //std::cout << p2.to_string() << std::endl;
    //std::cout << s.to_string() << std::endl;

    return 0;
}