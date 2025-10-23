/*
Przeliczanie wektora dlugosci z centymetrow na cale.
Poczatkowy wektor zainicjalizowany losowo.
*/

#include <iostream>
#include <vector>
#include <algorithm> // std::transform
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int n;
    cout << "Podaj liczbe elementow wektora: ";
    cin >> n;

    vector<double> cm(n);

    cout << "Wybierz sposob inicjalizacji:\n";
    cout << "1 - losowo\n";
    cout << "2 - recznie\n";
    cout << "Twoj wybor: ";
    int wybor;
    cin >> wybor;

    if (wybor == 1) {
        for (auto &x : cm)
            x = rand() % 100 + 1;
    } 
    else if (wybor == 2) {
        cout << "Podaj " << n << " dlugosci w cm:\n";
        for (auto &x : cm)
            cin >> x;
    } 
    else {
        cout << "Nieprawidlowy wybor. Koncze program.\n";
        return 0;
    }

    vector<double> inches(n);

    transform(cm.begin(), cm.end(), inches.begin(),
              [](double value) { return value / 2.54; });

    cout << "\nDlugosci w cm:     ";
    for (auto x : cm) cout << x << " ";

    cout << "\nDlugosci w calach: ";
    for (auto x : inches) cout << x << " ";

    cout << endl;
    return 0;
}