#include <stdio.h>

/**
 * @brief
 * int getchar(void) 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。这个函数在同一个时间内只会读取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。
 *
 * int putchar(int c) 函数把字符输出到屏幕上，并返回相同的字符。这个函数在同一个时间内只会输出一个单一的字符。您可以在循环内使用这个方法，以便在屏幕上输出多个字符。
 *
 */
void getchar_putchar()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
        if (c == '\n')
        {
            break;
        }
    }
}

/**
 * @brief Get the s puts object
 *
 * gets() 和 fgets() 函数
 * gets() 函数用于从标准输入设备读取一行字符串，但不推荐使用，因为它容易导致缓冲区溢出，推荐使用 fgets() 函数。
 *
 */
void gets_fgets()
{
    char str[100];
    // gets(str); // 'gets' is deprecated: This function is provided ,it is highly recommended that you use fgets(3) instead.
    // printf("gets str: %s\n", str);
    fgets(str, 100, stdin);
    printf("fgets str: %s\n", str);
}

/**
 * @brief
 * puts() 函数用于将一个字符串输出到标准输出设备，并自动在末尾添加换行符。
 *
 * fputs() 函数用于将字符串输出到指定的流（如标准输出、文件等），但不会自动在字符串末尾添加换行符。
 *  特点：
 *      不添加换行符：fputs() 不会在输出字符串后自动添加换行符。
 *      灵活的输出流：fputs() 可以输出到任意流，如标准输出、文件等。
 */
void puts_fputs()
{
    char str[100];
    printf("请输入要写入文件的字符串: ");
    fgets(str, 100, stdin);
    printf("puts:");
    puts(str);

    // 标准输出
    printf("fputs:");
    fputs(str, stdout);

    // 文件输出
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL)
    {
        printf("错误：无法创建文件 test.txt\n");
        return;
    }
    fputs(str, fp);
    fflush(fp); // 刷新缓冲区确保数据写入
    fclose(fp);
    printf("文件已成功写入 test.txt\n");
}

int main()
{
    // getchar_putchar();
    // gets_fgets();
    puts_fputs();
    return 0;
}
