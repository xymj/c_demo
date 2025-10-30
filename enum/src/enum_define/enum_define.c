#include <stdio.h>

// 注意：第一个枚举成员的默认值为整型的 0，后续枚举成员的值在前一个成员上加 1。我们在这个实例中把第一个枚举成员的值定义为 1，第二个就为 2，以此类推。
enum DAY
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

// 也可以在定义枚举类型时改变枚举元素的值：
enum season
{
    spring,
    summer = 3,
    autumn,
    winter
};
// 没有指定值的枚举元素，其值为前一元素加 1。也就说 spring 的值为 0，summer 的值为 3，autumn 的值为 4，winter 的值为 5

void enum_define()
{
    // 1、先定义枚举类型，再定义枚举变量
    enum DAY1
    {
        MONDAY1 = 1,
        TUESDAY1,
        WEDNESDAY1,
        THURSDAY1,
        FRIDAY1,
        SATURDAY1,
        SUNDAY1
    };
    enum DAY1 day1 = MONDAY1;
    printf("day1: %d\n", day1);

    // 2、定义枚举类型的同时定义枚举变量
    enum DAY2
    {
        MONDAY2,
        TUESDAY2,
        WEDNESDAY2,
        THURSDAY2,
        FRIDAY2,
        SATURDAY2,
        SUNDAY2
    } day2;
    day2 = TUESDAY2;
    printf("day2: %d\n", day2);

    // 3、省略枚举名称，直接定义枚举变量
    enum
    {
        MONDAY3,
        TUESDAY3 = 3,
        WEDNESDAY3,
        THURSDAY3,
        FRIDAY3,
        SATURDAY3,
        SUNDAY3
    } day3;
    day3 = WEDNESDAY3;
    printf("day3: %d\n", day3);
}
int main()
{
    enum_define();
    return 0;
}