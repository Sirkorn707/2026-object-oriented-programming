#include <iostream>
using namespace std;

int main() 
{
    int liczba;
    cout << "Podaj liczbe calkowita: ";
    cin >> liczba;
    
    if (liczba <= 0) {
        cout << "false" << endl;
        return 0;
    }
    
    if (liczba == 1) {
        cout << "true" << endl;
        return 0;
    }
    
    bool jestPotega = false;
    long long potega = 1;
    
    for (int i = 1; ; i++) {
        potega *= 3;
        
        if (potega == liczba) {
            jestPotega = true;
            break;
        }
        
        if (potega > liczba) {
            break;
        }
    }
    
    cout << (jestPotega ? "true" : "false") << endl;
    
    return 0;
}