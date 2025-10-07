// Zadanie 4.
// Napisz program, który losuje liczbę całkowitą z przedziału od 0 do 100, a następnie prosi użytkownika
// o odgadnięcie wylosowanej liczby i wprowadzenie jej z klawiatury. Następnie program wyświetla komunikat,
// czy wprowadzona liczba jest większa, czy mniejsza od wylosowanej. Gra kończy się w wypadku
// wprowadzenia poprawnej liczby lub przekroczenia maksymalnej liczby prób, która wynosi 5.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int losowaLiczba = rand() % 101; // Losuje liczbę od 0 do 100
    int liczbaUzytkownika = -1;
    //cout << "Liczba: " << losowaLiczba;

    while(liczbaUzytkownika!=losowaLiczba)
    {
        cout << "\nJaka liczbe wylosowal program?\n";
        cin >> liczbaUzytkownika;

        if (liczbaUzytkownika == losowaLiczba)
        {
            cout << "Tak jest! To ta liczba!\n";
            break;
        }
        if(liczbaUzytkownika > losowaLiczba)
        {
            cout << "Mniejsza!\n";
        }
        else
        {
            cout << "Wieksza!\n";
        }
    }
        
    //cout << "Liczba: " << losowaLiczba;

    
    return 0;
}
