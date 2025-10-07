// Zadanie 8.
// Napisz program, który wczytuje ze standardowego wejścia nieujemną liczbę całkowitą n (n > 2) i wypisuje na
// standardowym wyjściu największą liczbę k taką, że k dzieli n przy założeniu, że k < n. Algorytm
// wyszukiwania liczby k spełniającej powyższe warunki umieść w oddzielnej funkcji.
#include <iostream>
#include <cmath>
using namespace std;

int znajdzNajwiekszyWspolnyDzielnik(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return n / i;
        }
    }
    // Jeśli nie znaleziono NWD, to liczba jest pierwsza :D
    return 1;
}

int main() {
    int n;
    
    cout << "Podaj nieujemna liczbe calkowita n (n > 2): ";
    cin >> n;
    
    if (n <= 2) {
        cout << "Liczba musi byc wieksza od 2!" << endl;
        return 1;
    }
    
    int wynik = znajdzNajwiekszyWspolnyDzielnik(n);
    cout << "Najwieksza liczba k taka, ze k dzieli n i k < n: " << wynik << endl;
    
    return 0;
}