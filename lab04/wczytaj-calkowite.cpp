/*
Napisz program ktory wczyta z klawiatury dowolna ilosc liczb calkowitych. 
Wprowadzanie kolejnych ma sie skonczyc po wprowadzeniu liczby -1.
Wprowadzone liczby zapisac w wektorze.
Posługiwać się funkcjami z <algorithm>. 
a) usunac z wektora powtarzajace sie wartosci
b) policzyc i wyswietlic na ekranie liczbe nieparzystych elementow wektora
c) zmienic znak kazdego elementu wektora na przeciwny
d) posortowac wszystkie elememty wektora w malejacej kolejnosci
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers;
    int input;

    cout << "Wprowadzaj liczby calkowite (-1 konczy wprowadzanie):" << endl;
    while (true) {
        cin >> input;
        if (input == -1) break;
        numbers.push_back(input);
    }

    // a.
    sort(numbers.begin(), numbers.end());
    auto last = unique(numbers.begin(), numbers.end());
    numbers.erase(last, numbers.end());

    // b.
    int odd_count = count_if(numbers.begin(), numbers.end(),
                             [](int x) { return x % 2 != 0; });
    cout << "Liczba nieparzystych elementow: " << odd_count << endl;

    // c.
    transform(numbers.begin(), numbers.end(), numbers.begin(),
              [](int x) { return -x; });

    // d.
    sort(numbers.begin(), numbers.end(), greater<int>());

    cout << "Przetworzony wektor:" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}