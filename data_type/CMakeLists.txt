cmake_minimum_required(VERSION 3.10)

# 设置项目名称和语言为 C
project(data_type LANGUAGES C)

# 设置 C 标准为 C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 添加可执行文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)
add_executable(data_type ${SRC_LIST})

# 指定头文件搜索路径
target_include_directories(data_type PRIVATE include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")           # 开启所有警告,调试信息
set(CMAKE_C_FLAGS_DEBUG "-O0")             # 调试包不优化

# 将可执行文件生成到一个指定的位置/bin，而 ${PROJECT_SOURCE_DIR} 代表你的 CMakeLists.txt 的位置
set_target_properties(data_type PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

