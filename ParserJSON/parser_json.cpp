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

void ParserJson::Parse()
{
    // печать для типа начальная всегда для начала файла
    for (auto& element : JData.items())
    {
        if (GetBoolNull(element)) //GetNull
        {
            // PrintNull
            PrintKeyType(element);
        }
        if (GetBoolBoolean(element)) // GetBoolean
        {
            // PrintBoolen
            PrintKeyType(element);
        }
        if (GetBoolNumber(element))  // GetNumber
        {
            // Печатать
            PrintKeyType(element);
        }
        if (GetBoolString(element)) // GetString
        {
            // Печатать строку
            PrintKeyType(element);
        }
        if (GetBoolObject(element)) // GetObject
        {
            PrintKeyType(element);           

            ParserJson object(element.value(), this->FilleNameTxt);

            object.Parse();
        }
        if (GetBoolArray(element)) // GetArray
        {
            PrintKeyType(element);

            for (auto& arr_i : element.value().items())
            {
                PrintKeyType(arr_i);

                ParserJson array(arr_i.value(), this->FilleNameTxt); //  Возращает object

                array.Parse();
            }
        }
    }


}

bool ParserJson::GetBoolNull(auto BNull)
{
    return BNull.value().is_null();
}
bool ParserJson::GetBoolBoolean(auto BBool)
{
    return BBool.value().is_null();
}
bool ParserJson::GetBoolNumber(auto BNumber)
{
    return BNumber.value().is_null();
}
bool ParserJson::GetBoolString(auto BString)
{
    return BString.value().is_null();
}
bool ParserJson::GetBoolObject(auto BObject)
{
    return BObject.value().is_null();
}
bool ParserJson::GetBoolArray(auto BArray)
{
    return BArray.value().is_null();
}

void ParserJson::PrintKeyType(auto element)
{
    *FilleNameTxt << "\n\nКлюч: " << element.key() << '\n';
    *FilleNameTxt << "\n\nТип: " << element.value() << '\n';
}


