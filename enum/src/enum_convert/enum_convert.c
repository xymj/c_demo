#include <stdio.h>

// 将整数转换为枚举

int main()
{
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
    int code = 3;
    enum DAY day = code;
    printf("day: %d\n", day);

    enum DAY day2 = (enum DAY)code;
    printf("day2: %d\n", day2);
    return 0;
}