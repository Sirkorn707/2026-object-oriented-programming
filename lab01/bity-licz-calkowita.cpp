// Zadanie 7. 
// Posługując się operatorami bitowymi, napisz program, który wypisze na ekranie reprezentację bitową
// wprowadzonej z klawiatury liczby całkowitej. Przyjmij, że liczba może mieć maksymalnie 64 bity. Dodatkowo,
// oddziel każdą grupę ośmiu bitów znakiem spacji.
//
#include <iostream>
using namespace std;

int main() {
    long long liczba;
    
    cout << "Podaj liczbe calkowita: ";
    cin >> liczba;
    
    cout << "Reprezentacja bitowa:" << endl;
    
    for (int i = 63; i >= 0; i--) {
        // 1LL << i - tworzy maskę z bitem 1 na pozycji i
        // liczba & maska - operator AND bitowy sprawdza czy bit jest ustawiony
        // jeśli wynik jest różny od 0, bit jest ustawiony na 1
        cout << ((liczba & (1LL << i)) ? '1' : '0');
        
        if (i % 8 == 0 && i != 0) {
            cout << " ";
        }
    }
    
    cout << endl;
    return 0;
}