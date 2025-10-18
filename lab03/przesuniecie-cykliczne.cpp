/*
Zadanie 4.
W badaniach na strukturą genomu ważną rolę odgrywają sekwencje DNA będące cyklicznymi
przesunięciami innych sekwencji. Ciąg liter s jest przesunięciem cyklicznym ciągu t wtedy gdy oba ciągi
pokrywają się przy przesunięciu ciągu s o dowolną ilość liter. W wyniku przesunięcia cyklicznego, litery
wychodzące poza koniec napisu są przenoszone na jego początek. Na przykład, ciąg liter ACTGACG jest
cyklicznym przesunięciem ciągu TGACGAC. Napisz program, który wczyta z klawiatury dwie linie tekstu i
wypisze informację czy są one wzajemnie przesunięciem cyklicznym.
*/

#include <iostream>
#include <string>

bool czyCyklicznePrzesuniecie( const std::string & s1, const std::string & s2 )
{
    if( s1.size() != s2.size() )
    {
        return false;
    }

    std::string podwojoneS = s1 + s1;
    return ( podwojoneS.find( s2 ) != std::string::npos );
}

int main()
{
    std::string tekst1, tekst2;
    std::cout << "Podaj pierwszy tekst: ";
    std::getline( std::cin, tekst1 );
    std::cout << "Podaj drugi tekst: ";
    std::getline( std::cin, tekst2 );

    if( czyCyklicznePrzesuniecie( tekst1, tekst2 ) )
    {
        std::cout << "Teksty sa cyklicznymi przesunieciami." << std::endl;
    }
    else
    {
        std::cout << "Teksty nie sa cyklicznymi przesunieciami." << std::endl;
    }
    return 0;
}
/*
Zastanawia mnie jeszcze wsm czy wielkosc liter jeszcze powinna miec znaczenie tutaj, poki co dziala tak, ze ma, czyli ABC i cab to nie sa przesuniecia cykliczne.
*/