#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
    C 语言不允许返回一个完整的数组作为函数的参数。但是，您可以通过指定不带索引的数组名来返回一个指向数组的指针。
    如果您想要从函数返回一个一维数组，您必须声明一个返回指针的函数
 *
 */

// 动态分配数组内存，并返回一个指向数组的指针
int *getRandomNum(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return arr;
}

// 静态分配数组内存，并返回一个指向数组的指针，无法指定数组大小
int *getRandomNum2()
{
    // C 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量
    static int arr[10];
    int i = 0;
    srand((unsigned)time(NULL));
    for (i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        printf("static arr[%d] = %d\n", i, arr[i]);
    }
    return arr;
}

int main()
{
    int *arr_ptr = getRandomNum(10);
    printf("arr_ptr = %p\n", arr_ptr);
    for (int i = 0; i < 10; i++)
    {
        printf("arr_ptr[%d] = %d\n", i, arr_ptr[i]);
    }
    free(arr_ptr); // 动态申请需释放内存

    // 静态分配数组内存，并返回一个指向数组的指针，无需释放内存，程序结束时全局静态区会自动释放
    int *arr_ptr2 = getRandomNum2();
    printf("arr_ptr2 = %p\n", arr_ptr2);
    for (int i = 0; i < 10; i++)
    {
        printf("arr_ptr2[%d] = %d\n", i, arr_ptr2[i]);
    }

    return 0;
}