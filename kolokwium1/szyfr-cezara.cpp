#include <iostream>
#include <string>
using namespace std;

string szyfruj(const string& tekst, int klucz = 3) {
    string zaszyfrowany = "";
    
    for (char c : tekst) {
        if (c >= 'a' && c <= 'z') {
            char zaszyfrowanyZnak = ((c - 'a' + klucz) % 26) + 'a';
            zaszyfrowany += zaszyfrowanyZnak;
        } else if (c == ' ') {
            zaszyfrowany += ' ';
        }
    }
    
    return zaszyfrowany;
}

string deszyfruj(const string& zaszyfrowany, int klucz = 3) {
    string odszyfrowany = "";
    
    for (char c : zaszyfrowany) {
        if (c >= 'a' && c <= 'z') {
            char odszyfrowanyZnak = ((c - 'a' - klucz + 26) % 26) + 'a';
            odszyfrowany += odszyfrowanyZnak;
        } else if (c == ' ') {
            odszyfrowany += ' ';
        }
    }
    
    return odszyfrowany;
}

int main() {
    string tekst;
    
    cout << "Podaj tekst (tylko male litery i spacje): ";
    getline(cin, tekst);
    
    string zaszyfrowany = szyfruj(tekst);
    cout << "Tekst zaszyfrowany: " << zaszyfrowany << endl;
    
    string odszyfrowany = deszyfruj(zaszyfrowany);
    cout << "Tekst odszyfrowany: " << odszyfrowany << endl;
    
    return 0;
}