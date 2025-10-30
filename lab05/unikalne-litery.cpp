/*
Zadanie 4.
Program wczytujacy z klawiatury jeden wyraz i wypisuje na ekranie wszystkie unikalne litery
w wyrazie
*/

#include <iostream>
#include <string>
#include <set>

int main() {
    std::string wyraz;
    std::set<char> unikalneLitery;

    std::cout << "Wprowadz wyraz: ";
    std::cin >> wyraz;

    for (char litera : wyraz) {
        unikalneLitery.insert(litera);
    }

    std::cout << "Unikalne litery w wyrazie: ";
    for (char litera : unikalneLitery) {
        std::cout << litera << " ";
    }
    std::cout << std::endl;

    return 0;
}