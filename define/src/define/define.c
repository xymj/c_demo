#include <stdio.h>

// 定义常量宏
#define PI 3.1415926
#define GREETING "Hello, World!"

// 定义函数式宏（注意括号的使用）
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 条件编译示例
#define DEBUG 1

// 一个宏通常写在一个单行上。但是如果宏太长，一个单行容纳不下，则使用宏延续运算符（\）
// 字符串常量化运算符（#）: 在宏定义中，当需要把一个宏的参数转换为字符串常量时，则使用字符串常量化运算符（#）。在宏中使用的该运算符有一个特定的参数或参数列表
#define message_for(a, b) \
    printf(#a " and " #b ": We love you!\n")

// 标记粘贴运算符（##）: 宏定义内的标记粘贴运算符（##）会合并两个参数。它允许在宏定义中两个独立的标记被合并为一个标记。
#define tokenpaster(n) printf("token" #n " = %d", token##n)

// defined() 运算符:预处理器 defined 运算符是用在常量表达式中的，用来确定一个标识符是否已经使用 #define 定义过。
// 如果指定的标识符已定义，则值为真（非零）。如果指定的标识符未定义，则值为假（零）。
#if !defined(MESSAGE)
#define MESSAGE "You wish!"
#endif
int main()
{
    // 使用常量宏
    printf("PI的值: %f\n", PI);
    printf("%s\n", GREETING);

    // 使用函数式宏
    int x = 5;
    printf("%d的平方是: %d\n", x, SQUARE(x));
    printf("3和5中较大的数是: %d\n", MAX(3, 5));

// 条件编译示例
#ifdef DEBUG
    printf("[调试信息] 程序运行到main函数\n");
#endif

// 编译器版本检查
#if __STDC_VERSION__ >= 201112L
    printf("使用C11标准\n");
#elif __STDC_VERSION__ >= 199901L
    printf("使用C99标准\n");
#else
    printf("使用C89/C90标准\n");
#endif

    // 错误指令示例（取消注释将导致编译错误）
    // #error "这是一个手动触发的错误"

    // 打印当前源文件名（字符串常量）
    printf("当前文件: %s\n", __FILE__);

    // 打印编译日期（"MMM DD YYYY"格式）
    printf("编译日期: %s\n", __DATE__);

    // 打印编译时间（"HH:MM:SS"格式）
    printf("编译时间: %s\n", __TIME__);

    // 打印当前行号（十进制整数）
    printf("当前行号: %d\n", __LINE__);

    // 检查是否符合ANSI/ISO标准（1表示符合）
    printf("ANSI标准: %d\n", __STDC__);

    // 实用示例：调试信息输出
    printf("\n[调试信息] %s (第%d行) 编译于 %s %s\n",
           __FILE__, __LINE__, __DATE__, __TIME__);

    message_for(Carole, Debra);

    int token34 = 40;
    tokenpaster(34); // 实例会从编译器产生下列的实际输出：printf("token34 = %d", token34)

    printf("\n");
    printf("Here is the message: %s\n", MESSAGE);
    return 0;
}