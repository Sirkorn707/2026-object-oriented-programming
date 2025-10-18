/*
Zadanie 2. 
Napisz program, który wczyta z pliku jedną linię tekstu a następnie zapisze ją w nowym pliku w odwrotnej
kolejności. Posłuż się obiektami klasy string, ifstream oraz ofstream. Stwórz w programie funkcję
o nazwie string string_reverse(const string& in), która zwraca obiekt klasy string
z odwróconą kolejnością liter.
*/

#include <iostream>
#include <fstream> // biblioteka do operacji na plikach + obiekty ifstream i ofstream
#include <string>

std::string string_reverse(const std::string& in)
{
    std::string out;
    for( int i = in.size() - 1; i >= 0; --i )
    {
        out.push_back( in[i] );
    }
    return out;
}
/*
Jak dziala ta funkcja?
1. Funkcja przyjmuje sobie jako argument CONST REFERENCE do stringa o nazwie in.
2. Tworzy pusty string o nazwie out, który ma przechowywac odwrocony tekst.
3. Nastepnie funkcja iteruje przez znaki wejsciowego lancucha in od konca do poczatku, dodajac kazdy znak do lancucha out
za pomocą metody push_back() {adds new element at the end of vector after its current last element; potrzebuje std::vector zeby dzialac, a tutaj to nasz std::string out}. 
4. Po zakonczeniu petli funkcja zwraca odwrocony lancuch out.
*/

int main()
{
    std::ifstream inputFile("input.txt");
    if( !inputFile )
    {
        std::cout << "Nie mozna otworzyc pliku do odczytu!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(inputFile, line);
    inputFile.close();

    std::string reversedLine = string_reverse(line);

    std::ofstream outputFile("output.txt");
    if( !outputFile )
    {
        std::cout << "Nie mozna otworzyc pliku do zapisu!" << std::endl;
        return 1;
    }

    outputFile << reversedLine;
    outputFile.close();

    return 0;
}