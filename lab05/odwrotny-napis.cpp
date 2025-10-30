/*
Zadanie 5.
Posługując się stos, program który wypisuje na ekranie w odwrotniej kolejnosci
napisy wprowadzone z klawiatury.
Napisy oddzielone znakiem enter
Zakoncz wprowadzanie jesli wprowadzono slowo end.
*/

#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string wyraz;
    std::stack<std::string> stos1;

    while (true) {
        std::cout << "Wprowadz napis (lub 'end' aby zakonczyc): ";
        std::getline(std::cin, wyraz);
        if (wyraz == "end") {
            break;
        }
        stos1.push(wyraz);
    }

    std::cout << "Odwrotny napis: ";
    while (!stos1.empty()) {
        std::cout << stos1.top() << " ";
        stos1.pop();
    }
    std::cout << std::endl;

    return 0;
}