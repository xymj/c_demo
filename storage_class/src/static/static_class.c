#include <stdio.h>
#include "static/static_class.h"

/**
 * static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。

static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。

全局声明的一个 static 变量或方法可以被任何函数或方法调用，只要这些方法出现在跟 static 变量或方法同一个文件中。

静态变量在程序中只被初始化一次，即使函数被调用多次，该变量的值也不会重置。
 *
 */

/* 函数声明 */
void func1(void);

static int count = 10; /* 全局变量 - static 是默认的 */

int main()
{
    printf("static_const_num 为 %d\n", static_const_num);
    while (count--)
    {
        func1();
    }
    return 0;
}

void func1(void)
{
    /* 'thingy' 是 'func1' 的局部变量 - 只初始化一次
     * 每次调用函数 'func1' 'thingy' 值不会被重置。
     */
    static int thingy = 5;
    thingy++;
    printf(" thingy 为 %d ， count 为 %d\n", thingy, count);
}