/*
Zadanie 1.
Napisz program, który wczyta z klawiatury liczbę całkowitą a następnie za pomocą funkcji
rekurencyjnej wyliczy wartość silni tej liczby.
*/

#include <iostream>

int silnia(int n) 
{
    if (n <= 1) return 1;
    return n * silnia(n - 1);
}

int main()
{
    int n;
    std::cout << "Podaj liczbe calkowita: ";
    std::cin >> n;

    long long wynik = silnia(n);
    std::cout << "Silnia z " << n << " wynosi: " << wynik << std::endl;

    return 0;
}