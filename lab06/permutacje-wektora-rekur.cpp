/*
Zadanie 6.
Napisz program, który za pomocą rekurencyjnej funkcji wypisze na ekranie wszystkie permutacje
elementów wektora.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void wypiszPermutacje(std::vector<int>& wektor, int start) {
    if (start == wektor.size() - 1) {
        for (int i : wektor) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = start; i < wektor.size(); ++i) {
        std::swap(wektor[start], wektor[i]);
        wypiszPermutacje(wektor, start + 1);
        std::swap(wektor[start], wektor[i]);
    }
    // https://cplusplus.com/reference/algorithm/swap
}

int main() {
    std::vector<int> wektor = {1, 2, 3};
    std::cout << "Permutacje wektora: " << std::endl;
    wypiszPermutacje(wektor, 0);
    return 0;
}