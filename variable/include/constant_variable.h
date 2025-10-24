#ifndef __CONSTANT_VARIABLE_H__
#define __CONSTANT_VARIABLE_H__

/**
 * #define 与 const 区别
#define 与 const 这两种方式都可以用来定义常量，选择哪种方式取决于具体的需求和编程习惯。通常情况下，建议使用 const 关键字来定义常量，因为它具有类型检查和作用域的优势，而 #define 仅进行简单的文本替换，可能会导致一些意外的问题。

#define 预处理指令和 const 关键字在定义常量时有一些区别：

    替换机制：#define 是进行简单的文本替换，而 const 是声明一个具有类型的常量。#define 定义的常量在编译时会被直接替换为其对应的值，而 const 定义的常量在程序运行时会分配内存，并且具有类型信息。

    类型检查：#define 不进行类型检查，因为它只是进行简单的文本替换。而 const 定义的常量具有类型信息，编译器可以对其进行类型检查。这可以帮助捕获一些潜在的类型错误。

    作用域：#define 定义的常量没有作用域限制，它在定义之后的整个代码中都有效。而 const 定义的常量具有块级作用域，只在其定义所在的作用域内有效。

    调试和符号表：使用 #define 定义的常量在符号表中不会有相应的条目，因为它只是进行文本替换。而使用 const 定义的常量会在符号表中有相应的条目，有助于调试和可读性。
 *
 */

#define PI 3.14159265358979323846

/**
 *
 * 在多个源文件（main.c 和 constant_variable.c）中定义了同名的全局符号 _const_num，导致链接阶段出现重复符号错误。在C语言中，如果一个变量在多个编译单元中被定义（而不仅仅是声明），链接器无法确定使用哪一个，从而报错 duplicate symbol 6。
常见原因包括：
    将变量定义在头文件中并被多个 .c 文件包含；
    在多个 .c 文件中直接定义了同名的全局变量，而不是在一个文件中定义，在其他文件中用 extern 声明 3。
解决方法：
    确保全局变量只在一个 .c 文件中定义；
    在头文件中使用 extern 声明该变量，供其他文件引用；
    如果是常量，可考虑使用 static const 限定作用域，或使用 #define / enum 替代。
 *
 */
// const int const_num = 8; // error, duplicate symbol，被多个c文件引用
extern const int const_num;

static const int static_const_num = 10000;

int constant_variable();

#endif /* __CONSTANT_VARIABLE_H__ */