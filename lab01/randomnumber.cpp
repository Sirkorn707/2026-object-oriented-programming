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
