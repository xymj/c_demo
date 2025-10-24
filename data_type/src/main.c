#include <stdio.h>
#include <limits.h>

int main()
{
    // %lu 为 32 位无符号整数
    printf("char sizeof(char): %lu\n", sizeof(char));
    printf("char: %d ~ %d\n", CHAR_MIN, CHAR_MAX);
    printf("\n");

    printf("unsigned char sizeof(unsigned char): %lu\n", sizeof(unsigned char));
    printf("unsigned char: %d ~ %d\n", 0, UCHAR_MAX);

    printf("signed char sizeof(signed char): %lu\n", sizeof(signed char));
    printf("signed char: %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("\n");

    printf("short sizeof(short): %lu\n", sizeof(short));
    printf("short: %d ~ %d\n", SHRT_MIN, SHRT_MAX);

    printf("unsigned short sizeof(unsigned short): %lu\n", sizeof(unsigned short));
    printf("unsigned short: %d ~ %d\n", 0, USHRT_MAX);
    printf("unsigned short u: %d ~ %u\n", 0, USHRT_MAX);
    printf("\n");

    printf("int sizeof(int): %lu\n", sizeof(int));
    printf("int: %d ~ %d\n", INT_MIN, INT_MAX);

    printf("unsigned int sizeof(unsigned int): %lu\n", sizeof(unsigned int));
    printf("unsigned int: %d ~ %d\n", 0, UINT_MAX);
    printf("unsigned int u: %d ~ %u\n", 0, UINT_MAX);
    printf("\n");

    printf("long sizeof(long): %lu\n", sizeof(long));
    printf("long: %ld ~ %ld\n", LONG_MIN, LONG_MAX);

    printf("unsigned long sizeof(unsigned long): %lu\n", sizeof(unsigned long));
    printf("unsigned long: %d ~ %ld\n", 0, ULONG_MAX);
    printf("unsigned long lu: %d ~ %lu\n", 0, ULONG_MAX);
    printf("\n");
}