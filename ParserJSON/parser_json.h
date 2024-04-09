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
    std::ifstream* FilleNameJson;
    std::ofstream* FilleNameTxt;

    json JData; // full file >> JSON || Something key >> JData


public:
    ParserJson(json JName, std::ofstream* FilleTxt); // По объекту, который в своей структуре содержит другие сложные поля json
    ParserJson(std::ifstream* FilleJson, std::ofstream* FilleTxt); // по потоку чтения и записи
    ~ParserJson();

    template<class UnaryFunction>
    void recursive_iterate(const json& j, UnaryFunction f); // реекурсивная

    void Parse();

    

    // Открыть поток для чтения закрыть поток для чтения

    // Accessors and Mutators
    // void SetFileNameJson(std::ifstream FilleName);

    // std::string GetJson();
    // std::string GetTxt();

    // void SetJData(json);
    // json GetJData();
};
#endif // __PARSER__JSON__