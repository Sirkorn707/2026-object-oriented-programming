/* 
Zadanie 1.
Napisz program, który wczyta jedną linię tekstu z klawiatury do obiektu klasy string a następnie wypisze
na ekranie ilość cyfr występujących we wprowadzonym tekście. Porównaj działanie programu zarówno w
przypadku użycia operatora wejścia z obiektu cin oraz alternatywnie funkcji getline().
*/

#include <iostream>
#include <string>

int main()
{
    std::string tekst;
    std::cout << "Wprowadz linie tekstu: ";
    //std::cin >> tekst;
    std::getline( std::cin, tekst );

    int licznikCyfr = 0;
    for( char znak : tekst )
    {
        if( znak >= '0' && znak <= '9' )
        {
            licznikCyfr++;
        }
    }

    std::cout << "Ilosc cyfr w tekscie: " << licznikCyfr << std::endl;

    return 0;
}