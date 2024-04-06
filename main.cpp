#include "ParserJSON/single_include/nlohmann/json.hpp"

#include <iostream>
#include <fstream>

#include "parser_json.h"

int main() {
    std::string NameJson = "example.json";

    // открыть поток для чтения
    // открыть поток для записи
    ParserJson p(NameJson);
    // ... Передать ссылку на потоки
    p.Parse();
    // закрыть поток для записи
    // закрыть поток для чтения

    return 0;
}