/*
Zadanie 7.
Napisz program, który wczyta plik tekstowy i obliczy następujące statystyki:
a. Całkowita liczba wierszy.
b. Całkowita liczba słów (rozdzielone białymi znakami).
c. Całkowita liczba znaków (w tym spacje i znaki interpunkcyjne).
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream plik( "ex7test.txt" );
    if( !plik.is_open() )
    {
        std::cout << "Nie mozna otworzyc pliku!" << std::endl;
        return 1;
    }

    size_t liczbaWierszy = 0;
    size_t liczbaSlow = 0;
    size_t liczbaZnakow = 0;
    std::string linia;

    while( std::getline( plik, linia ) )
    {
        liczbaWierszy++;
        liczbaZnakow += linia.size() + 1;

        size_t pos = 0;
        while( pos < linia.size() )
        {
            while( pos < linia.size() && isspace( linia[pos] ) )
                pos++;
            if( pos < linia.size() )
            {
                liczbaSlow++;
                while( pos < linia.size() && !isspace( linia[pos] ) )
                    pos++;
            }
        }
    }

    plik.close();

    std::cout << "Liczba wierszy: " << liczbaWierszy << std::endl;
    std::cout << "Liczba slow: " << liczbaSlow << std::endl;
    std::cout << "Liczba znakow: " << liczbaZnakow << std::endl;

    return 0;
}