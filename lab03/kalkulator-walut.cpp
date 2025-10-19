/*
Zadanie 5.
Napisz program będący prostym kalkulatorem walut. Dla uproszczenia przyjmij, że program będzie operował
na walutach: PLN, USD oraz EUR. Stwórz jeden plik tekstowy w którym w oddzielnej linii będzie zapisany
kurs kupna 1 USD w każdej z dostępnych walut. W programie uwzględnij również tak zwany spread
walutowy w wysokości 5% (dla przypomnienia, spread walutowy to różnica pomiędzy ceną kupna i
sprzedaży waluty). Po uruchomieniu, program powinien wczytać dane z tego pliku. Następnie powinien
wyświetlić użytkownikowi menu umożliwiające wybór dwóch walut oraz kierunek konwersji. W następnej
kolejności użytkownik wprowadza sumę w walucie źródłowej po czym program wyświetla wartość w walucie
docelowej. Na koniec program umożliwia powrót do początkowego menu.
*/

#include <iostream>
#include <fstream>
#include <string>

float wczytajKurs( const std::string & nazwaPliku, const std::string & waluta )
{
    std::ifstream plik( nazwaPliku );
    if( !plik.is_open() )
    {
        std::cout << "Blad przy otwieraniu pliku!" << std::endl;
        return -1.0f;
    }

    std::string linia;
    while( std::getline( plik, linia ) )
    {
        size_t separatorPos = linia.find( ' ' );
        if( separatorPos != std::string::npos )
        {
            std::string kodWaluty = linia.substr( 0, separatorPos );
            float kurs = std::stof( linia.substr( separatorPos + 1 ) );
            if( kodWaluty == waluta )
            {
                plik.close();
                return kurs;
            }
        }
    }

    plik.close();
    std::cout << "Nie znaleziono kursu dla waluty: " << waluta << std::endl;
    return -1.0f;
}

int main()
{
    const std::string nazwaPliku = "kursyUSD.txt";
    const float spread = 0.05f; // spread walutowy 5%

    while( true )
    {
        std::cout << "Wybierz walute zrodlowa (PLN, USD, EUR) lub 'exit' aby zakonczyc: ";
        std::string walutaZrodlowa;
        std::cin >> walutaZrodlowa;
        if( walutaZrodlowa == "exit" || walutaZrodlowa == "EXIT") break;

        std::cout << "Wybierz walute docelowa (PLN, USD, EUR): ";
        std::string walutaDocelowa;
        std::cin >> walutaDocelowa;

        float kursZrodlowy = wczytajKurs( nazwaPliku, walutaZrodlowa );
        float kursDocelowy = wczytajKurs( nazwaPliku, walutaDocelowa );

        if( kursZrodlowy < 0 || kursDocelowy < 0 )
        {
            std::cout << "Blad wczytywania kursow. Sprobuj ponownie." << std::endl;
            continue;
        }

        std::cout << "Podaj kwote w " << walutaZrodlowa << ": ";
        float kwotaZrodlowa;
        std::cin >> kwotaZrodlowa;

        float kwotaPLN = kwotaZrodlowa * kursZrodlowy * ( 1 + spread );
        float kwotaDocelowa = kwotaPLN / kursDocelowy * ( 1 - spread );

        std::cout << kwotaZrodlowa << " " << walutaZrodlowa << " to " << kwotaDocelowa << " " << walutaDocelowa << std::endl;
    }

    return 0;
}