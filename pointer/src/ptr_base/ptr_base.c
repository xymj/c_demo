#include <stdio.h>

int main()
{
    int a = 10;
    // 指针也就是内存地址，指针变量是用来存放内存地址的变量。就像其他变量或常量一样，您必须在使用指针存储其他变量地址之前，对其进行声明。
    int *p = NULL;
    printf("init NULL p = %p\n", p);
    if (p)
    {
        printf("p is not NULL\n");
    }
    else
    {
        printf("p is NULL\n");
    }

    p = &a;

    if (p)
    {
        printf("p = &a is not NULL\n");
    }
    else
    {
        printf("p = &a is NULL\n");
    }

    printf("a = %d\n", a);
    printf("&a = %p\n", &a);
    printf("p = %p\n", p);
    printf("&p = %p\n", &p);
    printf("*p = %d\n", *p);
    return 0;
}