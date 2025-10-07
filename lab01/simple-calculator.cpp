// Zadanie 9.
// Składnia języka C/C++ udostępnia przydatną w niektórych sytuacjach instrukcję wyboru switch-case.
// Używając instrukcji switch-case, napisz niewielki kalkulator, który pobiera na wejściu jeden z operatorów
// arytmetycznych oraz dwa argumenty, po czym wyświetla wynik obliczeń otrzymany na podstawie tych
// danych. Program powinien zakończyć swoje działanie po wprowadzeniu litery q zamiast operatora
// arytmetycznego.
#include <iostream>
using namespace std;

int main() {
    char operacja;
    double a, b;
    
    cout << "Prosty kalkulator. \nDostepne operacje: +, -, *, /" << endl;
    cout << "Aby zakonczyc, wpisz 'q'." << endl;
    
    while (true) {
        cout << "Podaj operacje (+, -, *, /) lub 'q' aby zakonczyc: ";
        cin >> operacja;
        
        if (operacja == 'q') {
            cout << "Koniec programu." << endl;
            break;
        }
        
        cout << "Podaj dwie liczby: ";
        cin >> a >> b;
        
        switch (operacja) {
            case '+':
                cout << "Wynik: " << a + b << endl;
                break;
            case '-':
                cout << "Wynik: " << a - b << endl;
                break;
            case '*':
                cout << "Wynik: " << a * b << endl;
                break;
            case '/':
                if (b != 0) {
                    cout << "Wynik: " << a / b << endl;
                } else {
                    cout << "Blad: Dzielenie przez zero!" << endl;
                }
                break;
            default:
                cout << "Blad: Nieznana operacja!" << endl;
        }
    }
    
    return 0;
}