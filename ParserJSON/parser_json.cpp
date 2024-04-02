#include "parser_json.h"

#include <iostream>
#include <fstream>

ParserJson::ParserJson(std::string FileName)
{
    FileNameJson = FileName;

    std::ifstream file(FileName);

    json JData = json::parse(file);
}

ParserJson::~ParserJson()
{

}

// Processing is there a key?

json ParserJson::BringJObject(std::string name)
{
    json JObject = JData[name];
}

json ParserJson::BringJArray(std::string name)
{
    json JArray = JData[name];    
}

json ParserJson::BringJValue(std::string name)
{
    json JValue = JData[name];
} 

json ParserJson::BringJString(std::string name)
{
    json JString = JData[name];
} 

json ParserJson::BringJNumber(std::string name)
{
    json JNumber = JData[name];
}
