#include <stdio.h>
#include <stdlib.h>

/**
 * 函数指针作为某个函数的参数
函数指针变量可以作为某个函数的参数来使用的，回调函数就是一个通过函数指针调用的函数。
简单讲：回调函数是由别人的函数执行时调用你实现的函数。
 *
 */

// 直接通过定义函数指针形式参数，把函数指针作为函数的参数
void populate_array(int *array, int length, int (*getNextVal)(int))
{
    if (array == NULL || getNextVal == NULL)
    {
        return;
    }
    int maxVal = 100;
    for (int i = 0; i < length; i++)
    {
        array[i] = getNextVal(maxVal);
    }
}

int random_number(int maxVal)
{
    int num = rand();
    printf("num: %d\n", num);
    return num % maxVal;
}

// 通过 typedef 定义函数指针类型，把函数指针名称作为函数形式参数的类型
typedef int (*getMaxVal)(int, int);
typedef void (*callbackFuncPtr)(void);

int getArrayMaxVal(int *array, int size, getMaxVal compare_func)
{
    if (array == NULL || compare_func == NULL)
    {
        return -1;
    }
    int maxVal = array[0];
    for (int i = 1; i < size; i++)
    {
        maxVal = compare_func(maxVal, array[i]);
    }
    return maxVal;
}

int max_val(int a, int b)
{
    return a > b ? a : b;
}

void printf1()
{
    printf("printf1\n");
}
void printf2()
{
    printf("printf2\n");
}
void printf3()
{
    printf("printf3\n");
}
int main()
{
    int array[10];
    populate_array(array, 10, random_number);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }

    int maxVal = getArrayMaxVal(array, 10, max_val);
    printf("maxVal: %d\n", maxVal);

    callbackFuncPtr funcPtrs[] = {printf2, &printf1, &printf3}; // 函数指针数组, 其中函数的取地址符 & 符号可以省略
    int size = sizeof(funcPtrs) / sizeof(funcPtrs[0]);
    for (int i = 0; i < size; i++)
    {
        funcPtrs[i]();
    }
}