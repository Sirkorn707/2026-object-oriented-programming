/*
Zadanie 1.
Program zarządzający listą zakupów. Każdy zakupiony przedmiot jest reprezentowany
jako obiekt klasy string w kontenerze vector. Trzeba utworzyć funkcje o nazwie print,
która wypisuje na ekranie listę zakupów.
Main:
a) pusty wektor obiektow klasy string i wypisac na ekranie
b) dodac obiekty wino, buraki, banany, cukier, czekolada, marchew
c) wypisac na ekranie ostatni element i usunac go z wektora
d) dodac obiekt kawa jako trzeci w kolejnosci element w wektorze
e) napisac petle ktora znajduje w wektorze obiekt cukier a nastepnie zastepuje go obiektem cukeirki
f) petla ktora znajduje w wektorze obiekt czekolada i nastepnie go usuwa
g) posortowac wektor za pomoca funkcji sort z pliku naglowkowego algorithm
wypisac na ekranie stan wektora po kazdym z podpunktow
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void print(const vector<string>& lista) {
    cout << "Lista zakupow: ";
    for (const auto& item : lista) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    vector<string> listaZakupow;
    print(listaZakupow);

    listaZakupow.push_back("wino");
    listaZakupow.push_back("buraki");
    listaZakupow.push_back("banany");
    listaZakupow.push_back("cukier");
    listaZakupow.push_back("czekolada");
    listaZakupow.push_back("marchew");
    print(listaZakupow);

    if (!listaZakupow.empty()) {
        cout << "Ostatni element: " << listaZakupow.back() << endl;
        listaZakupow.pop_back();
    }
    print(listaZakupow);

    listaZakupow.insert(listaZakupow.begin() + 2, "kawa");
    print(listaZakupow);

    for (auto& item : listaZakupow) {
        if (item == "cukier") {
            item = "cukierki";
            break;
        }
    }
    print(listaZakupow);

    for (auto it = listaZakupow.begin(); it != listaZakupow.end(); ++it) {
        if (*it == "czekolada") {
            listaZakupow.erase(it);
            break;
        }
    }
    print(listaZakupow);

    sort(listaZakupow.begin(), listaZakupow.end());
    print(listaZakupow);

    return 0;
}