/*
Zadanie 6.
Zaprojektuj i zaimplementuj prostą bazę danych do przechowywania informacji o filmach i muzyce w twojej
bibliotece. Zastanów się jaka powinna być struktura rekordu i jak powinna być zaimplementowana?
Zaimplementuj podstawowe funkcjonalności: dodawanie i usuwanie rekordu, zapis i odczyt z pliku.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm> // remove_if()

struct MediaRecord {
    std::string title;
    std::string type; // "film" or "music"
    std::string artistOrDirector;
    int year;
};

class MediaDatabase {
private:
    std::vector<MediaRecord> records;
public:
    void addRecord(const MediaRecord& record) {
        records.push_back(record);
    }

    void removeRecord(const std::string& title) {
        records.erase(std::remove_if(records.begin(), records.end(),
            [&title](const MediaRecord& record) {
                return record.title == title;
            }), records.end());
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        for (const auto& record : records) {
            file << record.title << "," << record.type << ","
                 << record.artistOrDirector << "," << record.year << "\n";
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            MediaRecord record;
            std::stringstream ss(line);
            std::getline(ss, record.title, ',');
            std::getline(ss, record.type, ',');
            std::getline(ss, record.artistOrDirector, ',');
            ss >> record.year;
            records.push_back(record);
        }
    }
};

int main()
{
    MediaDatabase db;

    db.addRecord({"Inception", "film", "Christopher Nolan", 2010});
    db.addRecord({"The Dark Side of the Moon", "music", "Pink Floyd", 1973});

    db.saveToFile("media_database.txt");

    MediaDatabase db2;
    db2.loadFromFile("media_database.txt");

    db2.removeRecord("Inception");
    db2.saveToFile("media_database_updated.txt");

    return 0;
}