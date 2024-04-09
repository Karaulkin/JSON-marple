#include "ParserJSON/single_include/nlohmann/json.hpp"

#include <iostream>
#include <fstream>

#include "parser_json.h"

int main() {
    std::string NameJson = "example.json";
    std::string NameTxt = "example.txt";

    // открыть поток для чтения
    std::ofstream* fille_json = new std::ofstream(NameJson);
    //fille_json.open(NameJson);
    // открыть поток для записи
    std::ifstream* fille_txt = new std::ifstream(NameTxt);
    //fille_txt.open(NameTxt)
    // ... Передать ссылку на потоки
    ParserJson p(fille_json, fille_txt);
    p.Parse();
    // закрыть поток для записи
    // закрыть поток для чтения
    delete fille_json;
    delete fille_txt;

    return 0;
}