// Zadanie 10.
// Napisz program wczytujący ze standardowego wejścia dwie dodatnie liczby całkowite n i m, i wypisujący w
// kolejnych wierszach na standardowym wyjściu wszystkie dodatnie wielokrotności n mniejsze od m.
#include <iostream>

int main() {
	int n, m;
    std::cout << "Podaj dwie dodatnie liczby calkowite n i m: ";
	std::cin >> n >> m;
    if (n <= 0 || m <= 0) {
        std::cout << "Liczby musza byc dodatnie!" << std::endl;
        return 1;
    }

    if (n >= m) {
        std::cout << "Brak dodatnich wielokrotnosci n mniejszych od m." << std::endl;
        return 0;
    }

	for (int i = n; i < m; i += n) {
		std::cout << i << std::endl;
	}
	return 0;
}