#include <stdio.h>

/**
 * register 存储类
register 存储类用于定义存储在寄存器中而不是 RAM(电脑内存条，在CPU外) 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小（通常是一个字），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。

register 存储类定义存储在寄存器，所以变量的访问速度更快，但是它不能直接取地址，因为它不是存储在 RAM 中的。在需要频繁访问的变量上使用 register 存储类可以提高程序的运行速度。

{
   register int  miles;
}
寄存器只用于需要快速访问的变量，比如计数器。还应注意的是，定义 'register' 并不意味着变量将被存储在寄存器中，它意味着变量可能存储在寄存器中，这取决于硬件和实现的限制。
 */
void register_class_func()
{
    register int miles = 10;
    printf("miles: %d\n", miles);
}
int main()
{
    register_class_func();
    return 0;
}