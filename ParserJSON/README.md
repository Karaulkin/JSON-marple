Чтобы распарсить любой JSON файл с помощью библиотеки `json.hpp` (nlohmann/json), включая объекты, массивы, значения, строки и числа, вы можете использовать следующий подход. Этот пример демонстрирует, как прочитать JSON из файла и затем работать с различными типами данных в JSON.

1. **Чтение JSON из файла**:

```cpp
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main() {
    std::ifstream file("example.json");
    json data = json::parse(file);
}
```

2. **Работа с различными типами данных в JSON**:

После чтения JSON из файла, вы можете обращаться к различным типам данных в JSON. Вот примеры работы с различными типами данных:

- **Объект JSON**:

```cpp
json object = data["Image"]; // Получение объекта JSON по ключу
std::string title = object["Title"]; // Получение строки из объекта
bool animated = object["Animated"]; // Получение булевого значения из объекта
```

- **Массив JSON**:

```cpp
json array = object["IDs"]; // Получение массива JSON
for (auto& item : array) {
    std::cout << item << std::endl; // Вывод каждого элемента массива
}
```

- **Значение JSON**:

```cpp
json value = data["Image"]["Width"]; // Получение значения JSON
std::cout << value << std::endl; // Вывод значения
```

- **Строка JSON**:

```cpp
std::string title = data["Image"]["Title"]; // Получение строки JSON
std::cout << title << std::endl; // Вывод строки
```

- **Число JSON**:

```cpp
int width = data["Image"]["Width"]; // Получение числа JSON
std::cout << width << std::endl; // Вывод числа
```

Эти примеры демонстрируют, как работать с различными типами данных в JSON, используя библиотеку `json.hpp`. Вы можете адаптировать эти примеры в зависимости от структуры вашего JSON файла [2][3].

Citations:

[1] https://stackoverflow.com/questions/63398580/reading-arrays-of-json-objects-with-nlohmann-c-library

[2] https://json.nlohmann.me/api/basic_json/parse/

[3] https://github.com/nlohmann/json

[4] https://www.geeksforgeeks.org/how-to-parse-an-array-of-objects-in-cpp-using-rapidjson/

[5] https://json.nlohmann.me/api/basic_json/contains/

[6] https://github.com/nlohmann/json/issues/2805

[7] https://medium.com/@shivaniv.agarwal/parsing-complex-json-file-in-c-using-jsoncpp-9f6d9aba2a9b

[8] https://web.eecs.utk.edu/~jplank/plank/classes/cs302/Notes/JSON/

[9] https://danielaparker.github.io/jsoncons/