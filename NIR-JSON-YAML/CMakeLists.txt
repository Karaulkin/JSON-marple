cmake_minimum_required(VERSION 3.10)
project(ParserJSONProject)

# Указываем директорию, где находятся исходные файлы
set(SOURCE_DIR_1 "ParserJSON")
set(SOURCE_DIR_2 "Tabulation")

# Добавляем директорию с заголовочными файлами в список для поиска
include_directories(${SOURCE_DIR_1})
include_directories(${SOURCE_DIR_2})

# Добавляем директорию с подключаемой библиотекой в список для поиска
include_directories(${SOURCE_DIR_1}/single_include)

# Создаем исполняемый файл, указывая исходные файлы
add_executable(
		ParserJSONProject
		${SOURCE_DIR_1}/parser_json.cpp
		${SOURCE_DIR_2}/tabulation.cpp
		main.cpp
)
