#include <stdio.h>
#include <string.h>

int main()
{
    // 字符串实际上是使用空字符 \0 结尾的一维字符数组。因此，\0 是用于标记字符串的结束。

    // 空字符（Null character）又称结束符，缩写 NUL，是一个数值为 0 的控制字符，\0 是转义字符，意思是告诉编译器，这不是字符 0，而是空字符。
    char str[] = "hello world";
    printf("str: %s\n", str);
    printf("str len: %lu\n", strlen(str));
    printf("str size: %lu\n", sizeof(str) / sizeof(char));

    char str2[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
    printf("str2: %s\n", str2);
    printf("str2 len: %lu\n", strlen(str2));
    printf("str2 size: %lu\n", sizeof(str2) / sizeof(char));

    char str3[20];
    strcpy(str3, str2);
    printf("strcpy( str3, str2): %s\n", str3);

    // 演示问题：如果取消注释下面这行，会导致程序卡死或产生未定义行为
    // 原因是 str3 中的内容加上 str2 的内容超出了 str3 的容量（20个字符）
    // str3 当前包含 "hello world" (11个字符 + 1个null终止符 = 12个字符)
    // 再连接 "hello world" 需要额外的11个字符，总共需要23个字符的空间，但 str3 只有20个字符的空间
    // strcat(str3, str2); // error!! 执行代码到此行卡死原因
    printf("strcat( str3, str2):   %s\n", str3);
    printf("str3 len: %lu\n", strlen(str3));

    // 正确的做法是确保目标数组有足够的空间来容纳连接后的字符串
    char str4[30]; // 足够大的数组
    strcpy(str4, str2);
    strcat(str4, str2);
    printf("正确的strcat( str4, str2):   %s\n", str4);
    printf("str4 len: %lu\n", strlen(str4));

    // 或者使用更安全的函数如 strncat
    char str5[30];
    strcpy(str5, str2);
    strncat(str5, str2, sizeof(str5) - strlen(str5) - 1);
    printf("使用strncat的安全连接: %s\n", str5);
    printf("str5 len: %lu\n", strlen(str5));

    return 0;
}
