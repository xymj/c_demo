#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum COLOR
    {
        RED = 1,
        GREEN,
        BLUE
    } color;

    printf("please input color: 1 for RED, 2 for GREEN, 3 for BLUE\n");
    scanf("%d", &color);

    switch (color)
    {
    case RED:
        printf("you choose color: RED\n");
        break;
    case GREEN:
        printf("you choose color: GREEN\n");
        break;
    case BLUE:
        printf("you choose color: BLUE\n");
        break;
    default:
        printf("you choose color: error\n");
        break;
    }
}