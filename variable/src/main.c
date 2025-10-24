#include <stdio.h>
#include "constant_variable.h"

// 定义全局变量，C 语言中变量的默认值取决于其类型和作用域。全局变量和静态变量的默认值为 0，字符型变量的默认值为 \0，指针变量的默认值为 NULL，而局部变量没有默认值，其初始值是未定义的
int x;
int y;

// 函数声明+定义
int main_sum()
{
    // 局部变量，局部变量没有默认值，其初始值是未定义的，需初始化
    // int a;
    int a = 1;
    int b = 2;
    return a + b;
}

// 外部函数声明
int add();

// 对声明的常量进行初始化
const int const_num = 100;

int main()
{
    int result_sum = main_sum();
    printf("result_sum: %d\n", result_sum);
    int result_add = add();
    printf("result_add: %d\n", result_add);

    // 常量
    printf("PI: %f\n", PI);
    printf("const_num: %d\n", const_num);
    // printf("cv_num: %s\n", cv_num); // error: 'cv_num' undeclared (first use in this function)
    printf("constant_variable: %d\n", constant_variable());

    printf("static_const_num: %d\n", static_const_num);
    return 0;
}