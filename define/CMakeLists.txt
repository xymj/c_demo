cmake_minimum_required(VERSION 3.10)
project(define LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
set(CMAKE_C_FLAGS_DEBUG "-O0")

# 设置输出目录根路径
set(EXECUTABLE_OUTPUT_ROOT ${PROJECT_SOURCE_DIR}/bin)

# 获取 src 下的所有子目录
file(GLOB SUBDIRS RELATIVE ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/src/*)
foreach(SUBDIR ${SUBDIRS})
    set(SRC_DIR ${PROJECT_SOURCE_DIR}/src/${SUBDIR})
    if(IS_DIRECTORY ${SRC_DIR})
        # 查找该子目录下的 .c 文件
        file(GLOB SOURCES ${SRC_DIR}/*.c)
        if(SOURCES)
            # 提取目录名作为可执行文件名
            get_filename_component(TARGET_NAME ${SUBDIR} NAME)
            add_executable(${TARGET_NAME} ${SOURCES})
            target_include_directories(${TARGET_NAME} PRIVATE include)
            set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_ROOT})
        endif()
    endif()
endforeach()
