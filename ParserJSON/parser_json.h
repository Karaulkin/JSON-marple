#ifndef __PARSER__JSON__
#define __PARSER__JSON__

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class ParserJson
{
private:
    std::string FileNameJson;

    json JData; // full file >> JSON

    // Tags:
    json JObject; // Object json
    json JArray; // Array json
    json JValue; // Value json
    json JString; // String json
    json JNumber; // Number json

public:
    ParserJson(std::string FileName);
    ~ParserJson();
    
    //? ParserJson(json JNewObject); // если мы заходим в новый объект то создаем новый класс для работы с полями этого объекта

    // Parser tags: object, array, value, string, numbers
    json BringJObject(std::string name); // Bring object JSON by key
    json BringJArray(std::string name); // Bring array JSON by key
    json BringJValue(std::string name); // Bring value JSON by key
    json BringJString(std::string name); // Bring string JSON by key
    json BringJNumber(std::string name); // Bring number JSON by key

    // The parser inside the object
    // ... 

    //TODO Accessors and Mutators
    void SetFileNameJson(std::string FileName);
    std::string GetFileNameJson();

    std::string GetJson();
};

/*
    Возможно нужно унаследовать новую структуру,
    которая бы реализовывала вложенные объекты,
    то есть объекты json вложенные (JObjects)
*/
class ParserJObject : ParserJson
{
    private:
    /* data */
    public:
        ParserJObject(/* args */);
        ~ParserJObject();

};

/*
    Нужна структура, которая будет переводить патерны Maple формата
*/
class JsonToMaple
{
private:
    /* data */
public:
    JsonToMaple(/* args */);
    ~JsonToMaple();
};

#endif // __PARSER__JSON__