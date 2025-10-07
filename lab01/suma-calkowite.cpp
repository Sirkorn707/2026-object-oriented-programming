// Zadanie 11.
// Napisz program, który obliczy sumę dwóch dodatnich wartości całkowitych. Suma do obliczenia jest podana
// jako a ciąg, np. “123 + 37”, “78+ 99” itd. Program powinien działać następująco:
// a. Poproś użytkownika o wprowadzenie ciągu;
// b. Wyeliminuj dodatkowe spacje z ciągu;
// c. Wyodrębnij dwa podciągi reprezentujące dwa argumenty, takie jak „123” i „37”;
// d. Oblicz wartości całkowite tych dwóch podciągów, więc „123” jest przekształcane na wartość 123 itd.
// e. Wydrukuj sumę dwóch wartości;
// f. Rozszerz swoje rozwiązanie o obsługę potencjalnych błędów.
#include <iostream>
#include <string> // substr(), find(), empty()
#include <cctype> // isspace(), isdigit()

int main() {
    std::string rownanie;
    std::cout << "Podaj rownanie w postaci a + b, gdzie a i b to dwie dodatnie liczby calkowite: ";
    std::getline(std::cin, rownanie); // uzywam getline zeby cala linie wczytac, a nie tylko do pierwszej spacji

    std::string usuwanieSpacji;
    for (char znak : rownanie) {
        if (!isspace(znak)) {
            usuwanieSpacji += znak;
        }
    }

    size_t pozycjaPlusa = usuwanieSpacji.find('+');
    if (pozycjaPlusa == std::string::npos) {
        std::cout << "Blad: Brak znaku '+' w rownaniu." << std::endl;
        return 1;
    }
    // npos -> greatest possible value for size_t element
    // Source: https://cplusplus.com/reference/string/string/npos

    std::string liczba1 = usuwanieSpacji.substr(0, pozycjaPlusa);
    std::string liczba2 = usuwanieSpacji.substr(pozycjaPlusa + 1);

    if (liczba1.empty() || liczba2.empty()) {
        std::cout << "Blad: Brak jednej z liczb w rownaniu." << std::endl;
        return 1;
    }

    for (char znak : liczba1 + liczba2) {
        if (!isdigit(znak)) {
            std::cout << "Blad: Liczby musza byc dodatnimi wartosciami calkowitymi." << std::endl;
            return 1;
        }
    }

    int a = std::stoi(liczba1);
    int b = std::stoi(liczba2);
    // standard library function that turns a string into an integer.
    // Source: https://www.geeksforgeeks.org/cpp/stdstoi-function-in-cpp
    int suma = a + b;
    std::cout << "Suma: " << suma << std::endl;

	return 0;
}
