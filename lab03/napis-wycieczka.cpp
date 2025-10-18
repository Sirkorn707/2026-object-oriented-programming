/*
Zadanie 3.
Napisz program, który na początku tworzy napis o treści “Congratulations Mrs. <name>, you and
Mr. <name> are the lucky recipients of a trip for two to XXXXXX. Your trip to
XXX is already scheduled ”. Wykonaj następujące operacje na tym stringu:
a. Zastąp każde wystąpienie “<name>” słowem “Smith”,
b. zastąp każde wystąpienie XXXX (niezależnie od ilości liter X) słowem “Siberia”
c. dodaj słowo “un” bezpośrednio przed słowem “lucky”
d. dodaj słowo “in December” na końcu stringu.
e. wypisz powstały string na ekranie.
*/

#include <iostream>
#include <string>

int main()
{
    std::string tekst = "Congratulations Mrs. <name>, you and Mr. <name> are the lucky recipients of a trip for two to XXXXXX. Your trip to XXX is already scheduled ";
    std::cout << tekst << std::endl;

    // a.
    size_t pos = 0;
    std::string imieStare = "<name>";
    std::string imieNowe = "Smith";
    while ((pos = tekst.find(imieStare, pos)) != std::string::npos) {
        tekst.replace(pos, imieStare.length(), imieNowe);
        pos += imieNowe.length();
    }
    std::cout << tekst << std::endl;

    // b. 
    pos = 0;
    std::string xStary = "X";
    std::string xNowy = "Siberia";
    while ((pos = tekst.find(xStary, pos)) != std::string::npos) {
        size_t koncowaPozycja = pos;
        while (koncowaPozycja < tekst.length() && tekst[koncowaPozycja] == 'X') {
            koncowaPozycja++;
        }
        tekst.replace(pos, koncowaPozycja - pos, xNowy);
        pos += xNowy.length();
    }
    std::cout << tekst << std::endl;

    // c. 
    std::string luckyJuzNieTaki = "lucky";
    pos = tekst.find(luckyJuzNieTaki);
    if (pos != std::string::npos) {
        tekst.insert(pos, "un");
    }
    std::cout << tekst << std::endl;

    // d. 
    tekst += "in December."; // w sumie dziala XD prosta pilka

    // e. 
    std::cout << tekst << std::endl;

    return 0;
}