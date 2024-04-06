cmake_minimum_required(VERSION 3.10)
project(ParserJSONProject)

# Указываем директорию, где находятся исходные файлы
set(SOURCE_DIR "ParserJSON")

# Добавляем директорию с заголовочными файлами в список для поиска
include_directories(${SOURCE_DIR})

# Добавляем директорию с подключаемой библиотекой в список для поиска
include_directories(${SOURCE_DIR}/single_include)

# Создаем исполняемый файл, указывая исходные файлы
add_executable(ParserJSONProject ${SOURCE_DIR}/parser_json.cpp main.cpp)

# Если ваша подключаемая библиотека требует компиляции, добавьте ее здесь
# Например, если json.hpp является частью библиотеки, которую нужно скомпилировать:
# add_library(json_lib ${SOURCE_DIR}/single_include/json.hpp)
# target_link_libraries(ParserJSONProject PRIVATE json_lib)

# Если json.hpp является заголовочным файлом и не требует компиляции,
# то достаточно указать директорию с ним в include_directories, как показано выше.

# mkdir build
# cd build
# cmake ..
# make
