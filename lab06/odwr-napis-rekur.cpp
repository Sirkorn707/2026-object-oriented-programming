/*
Zadanie 3.
Napisz program, który posługując się funkcją rekurencyjną wypisze w odwrotnej kolejności
wprowadzony z klawiatury napis.
*/

#include <iostream>
#include <string>

void odwrocNapis(const std::string& napis, size_t index) 
{
    if (index == 0) return;
    std::cout << napis[index - 1];
    odwrocNapis(napis, index - 1);
}

int main() 
{
    std::string napis;
    std::cout << "Podaj napis: ";
    std::getline(std::cin, napis);

    std::cout << "Napis w odwrotnej kolejnosci: ";
    odwrocNapis(napis, napis.length());
    std::cout << std::endl;

    return 0;
}