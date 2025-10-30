#include <stdio.h>
#include <stdlib.h>

/**
 * 在 C 语言中，有两种类型的数组：
静态数组：编译时分配内存，大小固定。
动态数组：运行时手动分配内存，大小可变。
静态数组的生命周期与作用域相关，而动态数组的生命周期由程序员控制。
在使用动态数组时，需要注意合理地分配和释放内存，以避免内存泄漏和访问无效内存的问题。
 *
 */

/**
 * 静态数组是指在编译时确定大小的数组，其大小在程序运行期间不能改变。
在 C 语言中，静态数组的内存分配在栈区，通常使用方括号 [] 来定义。
静态数组的特点包括：
内存分配：静态数组的内存通常分配在栈上，随着函数的调用和返回而自动管理。
大小固定：在定义时指定大小，且在程序运行过程中不能更改。
效率：由于在栈上分配内存，访问速度较快。
生命周期：静态数组的生命周期始于其定义时。如果在函数内部定义，生命周期与函数的调用相同；如果在全局范围定义，生命周期贯穿整个程序运行。
 */
void static_type_array()
{
    int staticArray[] = {1, 2, 3, 4, 5}; // 静态数组声明并初始化
    // 对于静态数组，可以使用 sizeof 运算符来获取数组长度
    // sizeof(array) 返回整个数组所占用的字节数，而 sizeof(array[0]) 返回数组中单个元素的字节数
    int length = sizeof(staticArray) / sizeof(staticArray[0]);
    printf("staticArray length: %d\n", length);
    for (int i = 0; i < length; i++)
    {
        printf("staticArray[%d]: %d\n", i, staticArray[i]);
    }
}

/**
 * 动态数组是在运行时通过动态内存分配函数（如 malloc 和 calloc）手动分配内存的数组。

动态数组特点如下：

内存分配：动态数组的内存空间在运行时通过动态内存分配函数手动分配，并存储在堆上。需要使用 malloc、calloc 等函数来申请内存，并使用 free 函数来释放内存。
大小可变：动态数组的大小在运行时可以根据需要进行调整。可以使用 realloc 函数来重新分配内存，并改变数组的大小。
生命周期：动态数组的生命周期由程序员控制。需要在使用完数组后手动释放内存，以避免内存泄漏。
 */

void dynamic_type_array()
{
    int size = 5;
    int *dynamicArray = (int *)malloc(size * sizeof(int)); // 动态分配内存
    if (dynamicArray == NULL)
    {
        printf("内存分配失败\n");
        return;
    }
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &dynamicArray[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("dynamicArray[%d]: %d\n", i, dynamicArray[i]);
    }

    // 注意： 动态数组的使用需要注意内存管理的问题，确保在不再需要使用数组时释放内存，避免内存泄漏和访问无效的内存位置。
    free(dynamicArray); // 释放内存
}

int main()
{
    static_type_array();
    dynamic_type_array();
}