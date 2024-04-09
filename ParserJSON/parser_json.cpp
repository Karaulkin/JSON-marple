#include "parser_json.h"

#include <iostream>
#include <fstream>

/*
ParserJson::ParserJson(std::ofstream FilleJsonName) : FilleNameJson(FilleJsonName)
{
    this->FilleNameTxt = "conf_marple.txt";

    std::ifstream fille_json(FilleNameJson);
    std::ofstream fille_txt(FilleNameTxt); // если нету создаст

    if (!fille_json) {
        // throw
        std::cerr << "Не удалось открыть файл." << std::endl;
    }

    this->JData = json::parse(fille_json);
}
*/

ParserJson::ParserJson(json JName, std::ofstream* FilleTxt) : JData(JName), FilleNameTxt(FilleTxt)
{}

ParserJson::ParserJson(std::ifstream* FilleJson, std::ofstream* FilleTxt) : FilleNameJson(FilleJson), FilleNameTxt(FilleTxt)
{

    if (!*FilleNameJson) {
        // throw
        std::cerr << "Not found json." << std::endl;
    }

    this->JData = json::parse(*FilleNameJson);
}

ParserJson::~ParserJson()
{
    if (FilleNameJson)
    {
        FilleNameJson->close();
        delete FilleNameJson;
    }
    if (FilleNameTxt)
    {
        FilleNameTxt->close();
        delete FilleNameTxt;
    }
}

template<class UnaryFunction>
void ParserJson::recursive_iterate(const json& j, UnaryFunction f)
{ 
    for(auto it = j.begin(); it != j.end(); ++it)
    {
        if (it->is_structured())
        {
            *FilleNameTxt << it->first << '\n';
            recursive_iterate(*it, f);
        }
        else
        {
            f(it);
        }
    }
}

void ParserJson::Parse(){
    recursive_iterate(this->JData, [this](json::const_iterator it){
        *FilleNameTxt << it.key() << ':' << it.value() << '\n';
    });
}

// Тоскаем родителей
//https://stackoverflow.com/questions/45934851/c-nlohmann-json-how-to-iterate-find-a-nested-object