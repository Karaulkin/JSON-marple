#ifndef __PARSER__JSON__
#define __PARSER__JSON__

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class ParserJson
// будет реализовывать простые объекты
// отдельный класс поможет углубляться до простых 
// в помощь item и key и определение типа
// Задача:
// определить тип -> понять вложенные есть или нет -> показать
{
private:
    std::ofstream FilleNameJson;
    std::ifstream FilleNameTxt;

    json JData; // full file >> JSON || Something key >> JData


public:
    ParserJson(json JName, std::ifstream &FilleTxt); // По объекту, который в своей структуре содержит другие сложные поля json
    ParserJson(std::ofstream &FilleJson, std::ifstream &FilleTxt); // по потоку чтения и записи
    ~ParserJson();

    void Parse(); // реекурсивная

    // Открыть поток для чтения закрыть поток для чтения

    // Accessors and Mutators
    // void SetFileNameJson(std::ifstream FilleName);

    // std::string GetJson();
    // std::string GetTxt();

    // void SetJData(json);
    // json GetJData();

    bool GetBoolNull(auto BNull);
    bool GetBoolBoolean(auto BBool);
    bool GetBoolNumber(auto BNumber);
    bool GetBoolString(auto BString);
    bool GetBoolObject(auto BObject);
    bool GetBoolArray(auto BArray);

    void PrintKeyType(auto element);
};
#endif // __PARSER__JSON__