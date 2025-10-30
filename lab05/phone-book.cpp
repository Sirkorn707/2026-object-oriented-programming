/*
Zadanie 1.
Program - ksiazka telefoniczna

W petli powtarzanie:
- program prosi o wprowadzenie imienia osoby
- jesli wprowadzone imie juz wystepuje w ksiazce to nastepuje na ekranie wypisanie
numeru tej osoby
- jesli wprowadzone imie nie jest w ksiazce to program prosi o podanie numeru telefonu
i dodaje odpowiedni wpis do ksiazki
- jesli jako imie wprowadzono wyraz 'exit' wyjdz z petli i zakoncz program
*/

#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, std::string> phoneBook;
    std::string name;

    while (true) {
        std::cout << "Wprowadz imie ('exit' - wyjscie): ";
        std::getline(std::cin, name);

        if (name == "exit") {
            break;
        }

        auto it = phoneBook.find(name);
        if (it != phoneBook.end()) {
            std::cout << "Numer telefonu dla " << name << ": " << it->second << std::endl;
        } else {
            std::string phoneNumber;
            std::cout << "Nie znaleziono imienia. Podaj numer telefonu dla " << name << ": ";
            std::getline(std::cin, phoneNumber);
            phoneBook[name] = phoneNumber;
            std::cout << "Dodano wpis dla " << name << "." << std::endl;
        }
    }

    return 0;
}