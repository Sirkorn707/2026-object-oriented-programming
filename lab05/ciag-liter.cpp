/*
Zadanie 2.
Program który liczy i wypisze na ekranie czestosc wystepowania liter we wprowadzonym
z klawiatury stringu.
*/

#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<char, int> czestoscLiter;
    std::string wyraz;

    std::cout << "Wprowadz tekst: ";
    std::getline(std::cin, wyraz);

    for (char c : wyraz) {
        char wyraz_x = ' ';

        if (c >= 'A' && c <= 'Z') {
            wyraz_x = c + ('a' - 'A'); 
        } 
        else if (c >= 'a' && c <= 'z') {
            wyraz_x = c;
        } 
        else {
            continue; 
        }

        if (wyraz_x != ' ') {
            czestoscLiter[wyraz_x]++;
        }
    }

    std::cout << "\nCzestosc wystepowania liter:" << std::endl;
    std::cout << "----------------------------" << std::endl;

    for (const auto& para : czestoscLiter) {
        std::cout << "Litera '" << para.first << "': " << para.second << " razy" << std::endl;
    }

    return 0;
}