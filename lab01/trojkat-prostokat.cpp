// Zadanie 5.
// Napisz program, który wczytuje z klawiatury dodatnią liczbę całkowitą n i wypisuje wzór trójkąta
// prostokątnego o n rzędach z użyciem gwiazdek *. Wzór powinien być zgodny z następującymi zasadami:
// przeciwprostokątna (przekątna) i lewa krawędź są wykonane z *, wnętrze składa się ze spacji, podstawa
// (ostatni rząd) jest całkowicie wypełniona *. Na przykład dla n równego 5 program powinien wypisać na
// ekranie wzór:
// *
// **
// * *
// * *
// *****
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Podaj dodatnia liczbe calkowita n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Liczba musi byc dodatnia!" << endl;
        return 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}