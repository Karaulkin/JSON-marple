#ifndef PARSERJSONPROJECT_PARSER_JSON_H
#define PARSERJSONPROJECT_PARSER_JSON_H

#include "single_include/nlohmann/json.hpp"

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

        std::string begin = " %%begin";
        std::string end = "%%end";

        template<class BinaryFunction>
        void recursive_iterate(const json& j, BinaryFunction f, const std::string& parent_key = ""); // реекурсивная

        void printStruct(json::const_iterator it, const std::string& parent_key);



    public:
        ParserJson(std::ifstream& FilleJson, std::ofstream& FilleTxt); // по потоку чтения и записи

        void Parse();

        ~ParserJson();

        // Открыть поток для чтения закрыть поток для чтения

        // Accessors and Mutators
        // void SetFileNameJson(std::ifstream FilleName);

        // std::string GetJson();
        // std::string GetTxt();

        // void SetJData(json);
        // json GetJData();
    };
#endif // PARSERJSONPROJECT_PARSER_JSON_H