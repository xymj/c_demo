#include <stdio.h>

/**
 * auto 存储类
auto 存储类是所有局部变量默认的存储类。
定义在函数中的变量默认为 auto 存储类，这意味着它们在函数开始时被创建，在函数结束时被销毁。
{
   int mount;
   auto int month;
}
上面的实例定义了两个带有相同存储类的变量，auto 只能用在函数内，即 auto 只能修饰局部变量。
 */

void auto_class_func()
{
    auto int month = 10;
    printf("month: %d\n", month);
    int day = 60;
    printf("day: %d\n", day);
}
int main()
{
    auto_class_func();
    return 0;
}