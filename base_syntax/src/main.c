#include <stdio.h>

#define PI 3.14159265358979323846 // 宏定义

int sum(int a, int b); // 函数声明

int main(int argc, char const *argv[])
{
    printf("agrc: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("argv: %s\n", argv[i]);
    }

    printf("PI: %f\n", PI);

    int num1, num2, sum_res, i = 0; // 变量声明
    while (i < argc)
    {
        printf("请输入两个数: ");
        scanf("%d %d", &num1, &num2);

        // 函数调用
        sum_res = sum(num1, num2);
        printf("sum: %d\n", sum_res);
        i++;
    }

    return 0;
}

int sum(int a, int b) // 函数定义
{
    static int count = 0;
    count++;
    printf("count: %d\n", count);
    return a + b;
}