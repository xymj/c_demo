#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    // func_ptr 是一个函数指针
    int (*func_ptr)(int, int) = &max; // 函数指针赋值, &可以省略
    int a, b, c, d;
    printf("please input three num:\n");
    scanf("%d %d %d", &a, &b, &c);
    d = func_ptr(func_ptr(a, b), c);
    printf("max num: %d\n", d);
    return 0;
}