#include "ParserJSON/single_include/nlohmann/json.hpp"

#include <iostream>
#include <fstream>

#include "parser_json.h"

int main() {
    std::string NameJson = "example.json";
    std::string NameTxt = "example.txt";

    // открыть поток для чтения
    std::ofstream fille_json(NameJson);
    std::ifstream fille_txt(NameTxt);
    // открыть поток для записи
    ParserJson p(&fille_json, &fille_txt);
    // ... Передать ссылку на потоки
    p.Parse();
    // закрыть поток для записи
    // закрыть поток для чтения

    return 0;
}