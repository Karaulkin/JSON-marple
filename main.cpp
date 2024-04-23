#include "ParserJSON/single_include/nlohmann/json.hpp"

#include <iostream>
#include <fstream>

#include "parser_json.h"

int main() {
    std::string NameJson = "../example.json";
    std::string NameTxt = "example.txt";

    // открыть поток для чтения
    std::ifstream* fille_json = new std::ifstream(NameJson);
    //fille_json.open(NameJson);
    // открыть поток для записи
    std::ofstream* fille_txt = new std::ofstream(NameTxt, std::ios::app);
    //fille_txt.open(NameTxt)
    // ... Передать ссылку на потоки
    ParserJson p(fille_json, fille_txt);
    
    p.Parse();
    // закрыть поток для записи
    // закрыть поток для чтения

    return 0;
}