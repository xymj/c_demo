#include <stdio.h>

/**
 * 指针的每一次递增，它其实会指向下一个元素的存储单元。
指针的每一次递减，它都会指向前一个元素的存储单元。
指针在递增和递减时跳跃的字节数取决于指针所指向变量数据类型长度，比如 int 就是 4 个字节。
 *
 */

// 指针的递增操作会根据指针所指向的数据类型进行适当的内存偏移。int 类型是 sizeof(int)=4 个字节
void ptr_incr_int()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int i, *ptr = arr;
    printf("&arr: %p\n", &arr);
    printf("ptr: %p\n", ptr);
    printf("ptr value: %d\n", *ptr);
    for (i = 0; i < 5; i++)
    {
        printf("arr[%d] ptr: %p\n", i, ptr);
        printf("arr[%d] val: %d\n", i, *ptr);
        ptr++;
    }
}

// 指针的递增操作会根据指针所指向的数据类型进行适当的内存偏移。char 类型是 sizeof(char)=1 个字节
void ptr_incr_char()
{
    char str[] = "Hello";
    char i, *ptr = str;
    printf("&str: %p\n", &str);
    printf("ptr: %p\n", ptr);
    printf("ptr value: %c\n", *ptr);
    for (i = 0; i < 5; i++)
    {
        printf("str[%d] ptr: %p\n", i, ptr);
        printf("str[%d] val: %d, %c\n", i, *ptr, *ptr);
        // ptr++ 使指针从 str[0] 指向 str[1]。因为 ptr 是一个 char 类型指针，所以它递增时会移动 sizeof(char) 个字节，即 1 个字节。
        ptr++;
    }
}

struct Point
{
    int x;
    int y;
};

// 指针的递增操作会根据指针所指向的数据类型进行适当的内存偏移。struct Point 类型是 sizeof(struct Point)=8 个字节
void ptr_incr_struct()
{
    struct Point points[3] = {{1, 2}, {3, 4}, {5, 6}};
    struct Point *ptr = points;
    printf("&arr: %p\n", &points);
    printf("ptr: %p\n", ptr);
    printf("ptr value: %p\n", *ptr);
    for (int i = 0; i < 3; i++)
    {
        printf("points[%d] ptr: %p\n", i, ptr);
        printf("points[%d] val: %d\n", i, *ptr);
        printf("points[%d] val x: %d, y: %d\n", i, ptr->x, ptr->y);
        printf("point size: %ld\n", sizeof(*ptr));
        // ptr++ 使指针从 points[0] 指向 points[1]。因为 ptr 是一个 struct Point 类型指针，所以它递增时会移动 sizeof(struct Point) 个字节。
        ptr++;
    }
}

void ptr_decr_int()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = &arr[4];
    printf("&arr[4]: %p\n", &arr[4]);
    printf("ptr: %p\n", ptr);
    printf("ptr value: %d\n", *ptr);
    ptr--;

    printf("arr[3]: %p\n", &arr[3]);
    printf("ptr: %p\n", ptr);
    printf("ptr value: %d\n", *ptr);
}

void ptr_decr_char()
{
    char str[] = "Hello";
    char *ptr = &str[4];
    printf("&str[4]: %p\n", &str[4]);
    printf("ptr: %p\n", ptr);
    printf("ptr value: %c\n", *ptr);
    ptr--;

    printf("str[3]: %p\n", &str[3]);
    printf("ptr: %p\n", ptr);
    printf("ptr value: %c\n", *ptr);
}

// 可以比较指针来确定它们的关系。指针比较主要用于确定两个指针是否指向相同的内存位置或确定一个指针是否位于另一个指针之前或之后。
// 指针可以用关系运算符进行比较，如 ==、!=、<、>、<= 和 >=。如果 p1 和 p2 指向两个相关的变量，比如同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。
void ptr_compare()
{
    int a = 10, b = 20;
    int *p1 = &a, *p2 = &b, *p3 = &a;
    if (p1 == p2)
    {
        printf("p1 == p2\n");
    }
    else
    {
        printf("p1 != p2\n");
    }

    if (p1 == p3)
    {
        printf("p1 == p3\n");
    }
    else
    {
        printf("p1 != p3\n");
    }

    int arr[5] = {10, 20, 30, 40, 50};
    int *start = &arr[0];
    int *end = &arr[4];
    int *ptr = start;
    while (ptr <= end)
    {
        printf("ptr: %p\n", ptr);
        printf("ptr value: %d\n", *ptr);
        ptr++;
    }
}

void ptr_decr_struct()
{
    struct Point points[3] = {{1, 2}, {3, 4}, {5, 6}};
    struct Point *ptr = &points[2];
    printf("&points[2]: %p\n", &points[2]);
    printf("ptr: %p\n", ptr);
    printf("ptr value: %d, %d\n", (*ptr).x, ptr->y);
    ptr--;
    printf("points[1]: %p\n", &points[1]);
    printf("ptr: %p\n", ptr);
    printf("ptr value: %d, %d\n", (*ptr).x, ptr->y);
}

int main()
{
    ptr_incr_int();
    printf("*******************ptr_incr_int*********************\n");
    ptr_incr_char();
    printf("****************************************\n");
    ptr_incr_struct();
    printf("****************************************\n");
    ptr_decr_int();
    printf("*********************ptr_decr_int*******************\n");
    ptr_decr_char();
    printf("****************************************\n");
    ptr_decr_struct();
    printf("****************************************\n");
    ptr_compare();
    printf("********************ptr_compare********************\n");
    return 0;
}