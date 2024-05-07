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

parser::ParserJson::ParserJson(json JName, std::ofstream* FilleTxt, int tabulation) : JData(JName), FilleNameTxt(FilleTxt), tabs(tabulation)
{}

parser::ParserJson::ParserJson(std::ifstream* FilleJson, std::ofstream* FilleTxt) : FilleNameJson(FilleJson), FilleNameTxt(FilleTxt)
{
    if (!*FilleNameJson) {
        // throw
        std::cerr << "Not found json." << std::endl;
    }

    this->JData = json::parse(*FilleNameJson);
}

parser::ParserJson::~ParserJson()
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

template<class BinaryFunction>
void parser::ParserJson::recursive_iterate(const json& j, BinaryFunction f, const std::string& parent_key) 
{
    tabs++;
    for(auto it = j.begin(); it != j.end(); ++it)
    {
        std::string key = it.key();
        if (it->is_object())
        {
            printStruct(it, parent_key);
            tab++;
            recursive_iterate(*it, f, key);
            tab--;
            *FilleNameTxt << PrintTabs() << end << '\n';
        }
        else if (it->is_array())
        {
            //*FilleNameTxt << parent_key << ':' << key << '\n';
            *FilleNameTxt << PrintTabs() << key << " =" << begin << '\n';
            tab++;
            for (size_t i = 0; i < it->size(); ++i)
            {
                //*FilleNameTxt << parent_key << ':' << key << '[' << std::to_string(i) << "]:" << '\n' /*<< (*it)[i] << '\n'*/; 
                *FilleNameTxt << PrintTabs() << key << "[Index:" << std::to_string(i) << "] =" << begin << '\n';
                //recursive_iterate((*it)[i], f, parent_key + "[" + key + "][" + std::to_string(i) + "]");
                recursive_iterate((*it)[i], f, parent_key);
                *FilleNameTxt << PrintTabs() << end << '\n';
            }
            tab--;
            *FilleNameTxt << PrintTabs() << end << '\n';
        }
        else
        {
            f(it, parent_key);
        }
    }
}


void parser::ParserJson::Parse(){
    recursive_iterate(this->JData, [this](json::const_iterator it, const std::string& parent_key){
        *FilleNameTxt << PrintTabs() << it.key()<< " = " << it.value() << '\n';
    });
}

void parser::ParserJson::printStruct(json::const_iterator it, const std::string& parent_key)
{
    //*FilleNameTxt << parent_key << ':' << it.key() << '\n';
    *FilleNameTxt << PrintTabs() << it.key() << " =" << begin << '\n';
}

/*
void ParserJson::printArrayIndex(json::const_iterator it, const std::string& parent_key)
{
    *FilleNameTxt << parent_key << ':' << std::distance(it->begin(), it) << '\n';
}
*/


// Тоскаем родителей
//https://stackoverflow.com/questions/45934851/c-nlohmann-json-how-to-iterate-find-a-nested-object

std::string parser::ParserJson::PrintTabs()
{
    std::string tabulation;

    for(int i = 0; i < tabs; i++)
    {
        tabulation += '\t';
    }
    return tabulation;

}