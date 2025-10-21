#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Podaj liczbe calkowita: ";
    cin >> n;
    
    long long silnia = 1;
    for (int i = 1; i <= n; i++) {
        silnia *= i;
    }
    
    cout << "Silnia z " << n << " wynosi: " << silnia << endl;
    
    return 0;
}