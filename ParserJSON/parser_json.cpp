#include "parser_json.h"

#include <iostream>
#include <fstream>

ParserJson::ParserJson(std::string FileJsonName) : FileNameJson(FileJsonName)
{
    this->FilleNameTxt = "conf_marple.txt";

    std::ifstream file_json(FileNameJson);
    std::ofstream file_txt(FilleNameTxt); // если нету создаст

    if (!file_json) {
        // throw
        std::cerr << "Не удалось открыть файл." << std::endl;
    }

    this->JData = json::parse(file_json);
}

ParserJson::ParserJson(json JName) : FileNameJson(nullptr), FilleNameTxt(nullptr)
{
    this->JData = JName;

    // нужен конструктор копирования
}

ParserJson::ParserJson(std::string FileJson, std::string FileTxt) : FileNameJson(FileJson), FilleNameTxt(FileTxt)
{
    std::ifstream file_json(FileNameJson);
    std::ofstream file_txt(FilleNameTxt); // если нету создаст

    if (!file_json) {
        // throw
        std::cerr << "Not found json." << std::endl;
    }

    this->JData = json::parse(file_json);
}

ParserJson::~ParserJson() = default;

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

            ParserJson object(element.value());

            object.Parse();
        }
        if (GetBoolArray(element)) // GetArray
        {
            PrintKeyType(element);

            for (auto& arr_i : element.value().items())
            {
                PrintKeyType(arr_i);

                ParserJson array(arr_i.value()); //  Возращает object

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
    std::cout << "\n\nКлюч: " << element.key() << '\n';
    std::cout << "\n\nТип: " << element.value() << '\n';
}


