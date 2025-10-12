// Utwórz klasę o nazwie SmartArray, która reprezentuje tablicę liczb całkowitych. Klasa powinna zawierać
// następujące pola i metody:
// a. konstruktor, którego argumentem jest rozmiar tablicy i który wypełnia tablicę liczbami losowymi oraz
// wypisuje na ekranie komunikat informujący o utworzeniu obiektu wraz z wartościami argumentów
// konstruktora,
// b. konstruktor kopiujący który oprócz utworzenia kopii obiektu wypisuje też na ekranie komunikat o
// utworzeniu obiektu za jego pomocą,
// c. destruktor, który wypisuje na ekranie komunikat informujący o wywołaniu destruktora,
// d. metodę o nazwie at, która zwraca element tablicy pod wskazanym indeksem. (Posłuż się makrem
// assert, by sprawdzić, czy podany indeks jest poprawny).
// e. metodę, która umożliwia ustawienie elementu tablicy pod wskazanym indeksem,
// f. metodę, która zwraca wartość maksymalną w tablicy,
// g. metodę o nazwie print, która wypisuje na ekranie zawartość tablicy,
// W funkcji main utwórz obiekt klasy SmartArray o liczbie elementów 16. Za pomocą metody print
// wypisz na ekranie zawartość tablicy. Zmodyfikuj dowolny element w tablicy, a następnie wypisz na ekranie
// maksymalną wartość w tablicy. Ponownie wypisz na ekranie zawartość tablicy. Następnie utwórz nowy
// obiekt, posługując się konstruktorem kopiującym. Wypisz na ekranie zawartość nowego obiektu. Sprawdź
// działanie makra assert w metodzie at, podając jako argument niepoprawną wartość indeksu.

#include <iostream>
#include <assert.h>

class SmartArray
{
    private:
        int* arr;
        size_t size;
    public:
        SmartArray(size_t s) : size(s) // a
        {
            arr = new int[size];
            for (size_t i = 0; i < size; ++i)
            {
                arr[i] = rand() % 100;
            }
            std::cout << "SmartArray rozmiaru " << size << " zostala stworzona :D." << std::endl;
        }
        SmartArray(const SmartArray& other) : size(other.size) // b
        {
            arr = new int[size];
            for (size_t i = 0; i < size; ++i)
            {
                arr[i] = other.arr[i];
            }
            std::cout << "SmartArray rozmiaru " << size << " zostala skopiowana :D." << std::endl;
        }
        ~SmartArray() // c
        {
            delete[] arr;
            std::cout << "SmartArray rozmiaru " << size << " zostala zniszczona :D." << std::endl;
        }
        int& at(size_t index) // d 
        {
            assert(index < size);
            return arr[index];
        }
        void set(size_t index, int value) // e
        {
            assert(index < size);
            arr[index] = value;
        }
        int max() const // f 
        {
            int maxValue = arr[0];
            for (size_t i = 1; i < size; ++i)
            {
                if (arr[i] > maxValue)
                {
                    maxValue = arr[i];
                }
            }
            return maxValue;
        }
        void print() const // g 
        {
            for (size_t i = 0; i < size; ++i)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
};

int main()
{
    SmartArray sa(16);
    sa.print();
    sa.set(5, 100); // zmiana elementu o indeksie 5
    std::cout << "Maksymalna wartosc w tablicy: " << sa.max() << std::endl;
    sa.print();

    SmartArray sa2 = sa; // konstruktor kopiujacy
    sa2.print();

    // Test assert -> wartosc niepoprawna
    //std::cout << sa.at(20) << std::endl; // niepoprawny indeks

    return 0;
}