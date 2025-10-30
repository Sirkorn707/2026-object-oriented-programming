/*
Zadanie 3.
Program ktory wyswietli numery linii dla wszystkich wprowadzonych z klawiatury wyrazow.
Przyjac ze pierwszy wyraz znajduje sie w linii numer 1.
Program ma dzialac w taki sposob:
- powtarzac w petli:
-- wprowadzic wyraz z klawiatury
-- jesli wprowadzi sie slowo "end" to zakonczyc wprowadzenie wyrazow i wyswietlic
na ekranie numery linii w ktorych wystepuja wszystkie wprowadzone wyrazy 
*/

#include <iostream>
#include <string>
#include <map>
#include <set>

int main() {
    std::map<std::string, std::set<int>> linijka;
    std::string wyraz;
    int nrLinii = 1;

    std::cout << "Wprowadzaj wyrazy (wpisz 'end' aby zakonczyc):" << std::endl;

    while (true) {
        std::cin >> wyraz;
        if (wyraz == "end") {
            break;
        }
        linijka[wyraz].insert(nrLinii);
        nrLinii++;
    }

    std::cout << "\nNumery linii dla wprowadzonych wyrazow:" << std::endl;
    for (const auto& wej : linijka) {
        std::cout << "Wyraz: " << wej.first << " - Linie: ";
        for (const auto& line : wej.second) {
            std::cout << line << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}