#include <iostream>

//#ifdef __PARSER__JSON__


#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class ParserJson
{
private:
    std::string S_FileName;

    json J_Data;

public:
    ParserJson(std::string FileName);
    ~ParserJson();

    // Parser tegs: object, array, value, string, numbers
    

    // Accessors and Mutators
    void SetJsonFileName(std::string FileName);
    std::string GetJsonFileName();

    std::string GetJson();
};


//#endif // __PARSER__JSON__