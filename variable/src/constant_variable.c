#include <stdio.h>
#include "constant_variable.h"

// 对声明的常量进行初始化
// const int const_num = 800; error, duplicate symbol, 被多个c文件引用进行定义初始化
int constant_variable()
{
    const int cv_num = 100;
    printf("func cv_num: %d\n", cv_num);
    // printf("func const_num: %d\n", const_num); error
    printf("func static_const_num: %d\n", static_const_num);
    return cv_num;
}