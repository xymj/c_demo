#include <stdio.h>

int main()
{
    // 指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。
    // 通常，一个指针包含一个变量的地址。当我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。
    int v = 10;
    int *ptr = &v;
    int **ptr_save_ptr = &ptr;
    printf("ptr: %p\n", ptr);
    printf("ptr_save_ptr: %p\n", ptr_save_ptr);
    printf("*ptr: %d\n", *ptr);
    printf("*ptr_save_ptr: %p\n", *ptr_save_ptr);
    printf("**ptr_save_ptr: %d\n", **ptr_save_ptr);
}