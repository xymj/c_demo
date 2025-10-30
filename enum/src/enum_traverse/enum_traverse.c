#include <stdio.h>

// 枚举类型是被当做 int 或者 unsigned int 类型来处理的，所以按照 C 语言规范是没有办法遍历枚举类型的。
// 不过在一些特殊的情况下，枚举类型必须连续是可以实现有条件的遍历。

enum DAY
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} day;

// 枚举类型不连续，这种枚举无法遍历
enum COLOR
{
    RED,
    BLUE,
    GREEN = 10,
    YELLOW,
    BLACK,
    WHITE
} color;

void enum_traverse()
{
    for (day = MONDAY; day <= SUNDAY; day++)
    {
        printf("day: %d\n", day);
    }

    // 遍历异常，出现2-9不存在的枚举值
    for (color = RED; color <= WHITE; color++)
    {
        printf("color: %d\n", color);
    }
}

int main()
{
    enum_traverse();
    return 0;
}