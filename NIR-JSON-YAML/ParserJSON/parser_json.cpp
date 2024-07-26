#include "parser_json.h"

#include <iostream>
#include <fstream>
#include <string>

/**
 * The function `ParserJson` takes an input JSON file and an output text file, reads the JSON data, and
 * stores it for further processing.
 * 
 * @param FilleJson `FilleJson` is a reference to an input file stream (`std::ifstream`) that is used
 * to read a JSON file.
 * @param FilleTxt The `FilleTxt` parameter is a reference to an `std::ofstream` object, which is used
 * for writing data to a file. In the provided code snippet, it is being assigned to the `FilleNameTxt`
 * member variable of the `ParserJson` class.
 */
ParserJson::ParserJson(std::ifstream& FilleJson, std::ofstream& FilleTxt)
{
    FilleNameTxt = &FilleTxt;
    FilleNameJson = &FilleJson;

    if (!*FilleNameJson) {
        // throw
        std::cerr << "Not found json." << std::endl;
    }

    this->JData = json::parse(*FilleNameJson);
}

/**
 * The above function is the destructor for the ParserJson class in C++.
 */
ParserJson::~ParserJson()
{}

/* The `recursive_iterate` function in the `ParserJson` class is a recursive function that iterates
over a JSON object or array and performs certain actions based on the type of the JSON element. Here
is a breakdown of what the function does: */
template<class BinaryFunction>
void ParserJson::recursive_iterate(const json& j, BinaryFunction f, const std::string& parent_key) 
{
    for(auto it = j.begin(); it != j.end(); ++it)
    {
        std::string key = it.key();

        if (it->is_object())
        {
            printStruct(it, key);
            recursive_iterate(*it, f, key);
            *FilleNameTxt << end << '\n';
        }
        else if (it->is_array())
        {
            //*FilleNameTxt << key << " =" << begin << '\n';

            for (size_t i = 0; i < it->size(); ++i)
            {
                *FilleNameTxt << key << "[" << std::to_string(i+1) << "] =" << begin << '\n';

                recursive_iterate((*it)[i], f, parent_key);

                *FilleNameTxt << end << '\n';
            }

            //*FilleNameTxt << end << '\n';
        }
        else
        {
            f(it, parent_key);
        }
    }
}


/**
 * The Parse function iterates through a JSON object and prints key-value pairs to a text file.
 */
void ParserJson::Parse()
{
    recursive_iterate(this->JData, [this](json::const_iterator it, const std::string& parent_key)
    {
        *FilleNameTxt << it.key()<< " = " << it.value() << '\n';
    });
}

/**
 * The function `printStruct` prints a key-value pair from a JSON object with indentation specified by
 * the `tabs` parameter.
 * 
 * @param it The parameter `it` is an iterator pointing to a specific element in a JSON object.
 * @param tabs The `tabs` parameter in the `printStruct` function is a string that represents the
 * indentation level for the output. It is used to format the output in a structured and readable way
 * by adding appropriate indentation based on the nesting level of the JSON structure being printed.
 */
void ParserJson::printStruct(json::const_iterator it, const std::string& tabs)
{
    *FilleNameTxt << it.key() << " =" << begin << '\n';
}