/*
Zadanie 5.
Napisz program, który rekurencyjnie sprawdza czy podana liczba naturalna jest pierwsza.
*/

#include <iostream>

bool czyLiczbaPierwsza(int n, int dzielnik = 2) 
{
    if (n < 2) return false;
    if (dzielnik * dzielnik > n) return true;
    if (n % dzielnik == 0) return false;
    return czyLiczbaPierwsza(n, dzielnik + 1);
}

int main() 
{
    int n;
    std::cout << "Podaj liczbe naturalna: ";
    std::cin >> n;

    if (czyLiczbaPierwsza(n)) 
    {
        std::cout << n << " jest liczba pierwsza." << std::endl;
    } 
    else 
    {
        std::cout << n << " nie jest liczba pierwsza." << std::endl;
    }

    return 0;
}