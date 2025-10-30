#include <stdio.h>
#include <string.h>
// 共用体是一种特殊的数据类型，允许您在相同的内存位置存储不同的数据类型。
// 您可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值。共用体提供了一种使用相同的内存位置的有效方式。

/**
 * Data 类型的变量可以存储一个整数、一个浮点数，或者一个字符串。这意味着一个变量（相同的内存位置）可以存储多个多种类型的数据。您可以根据需要在一个共用体内使用任何内置的或者用户自定义的数据类型。

共用体占用的内存应足够存储共用体中最大的成员。
Data 将占用 20 个字节的内存空间，因为在各个成员中，字符串所占用的空间是最大的
 *
 */

union Data
{
    int i;
    float f;
    char str[20];
};

typedef union Data DATA_TYPE;
int main()
{
    union Data data;
    printf("size of union data: %ld\n", sizeof(data));

    data.i = 10;
    data.f = 3.14;
    strcpy(data.str, "hello world");
    printf("data.i: %d\n", data.i);     // 被覆盖
    printf("data.f: %f\n", data.f);     // 被覆盖
    printf("data.str: %s\n", data.str); // 正常值

    DATA_TYPE data2;
    printf("size of union data2: %ld\n", sizeof(data2));
    data2.i = 10;
    printf("data2.i: %d\n", data2.i);
    data2.f = 3.14;
    printf("data2.f: %f\n", data2.f);
    strcpy(data2.str, "hello world");
    printf("data2.str: %s\n", data2.str);
    return 0;
}