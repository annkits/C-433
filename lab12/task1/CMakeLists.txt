# Задание: задать имя проекта и версию cmake, добавить subdirectory для background и pipes, в которых 
# тоже есть свои CMakeLists.txt (внутри них тоже нужно добавить одну-две строки для сборки, задание описано в них же)
# Решить проблему с заголовочными файлами, включив директории в корневом CMakeLists.txt (include_directories)
# Слинковать исполняемый файл из src/main.c с библиотекой background
# Все это дело собрать, используя cmake и make
# Для установки cmake нужно установить его: sudo apt install build-essential cmake -y

cmake_minimum_required(VERSION 3.10) 
                                     
project(hello_cmake)    
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -I ./background -I ./pipes")
include_directories("./background" "./pipes")  
add_executable(main ./src/main.c ./background/background.c ./pipes/read_pipe.c ./pipes/write_pipe.c)
