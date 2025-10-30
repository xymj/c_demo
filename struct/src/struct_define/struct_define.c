#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
// 同时又声明了结构体变量s1
// 这个结构体并没有标明其标签
struct
{
    int a;
    char b;
    double c;
} s1;

// 此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
// 结构体的标签被命名为SIMPLE,没有声明变量
struct SIMPLE
{
    int a;
    char b;
    double c;
};
// 用SIMPLE标签的结构体，另外声明了变量t1、t2、t3
struct SIMPLE t1, t2[20], *t3;

typedef struct SIMPLE SIMPLE2; // 这样定义变量无需带struct关键字

// 也可以用typedef创建新类型
typedef struct
{
    int a;
    char b;
    double c;
} Simple2;
// 现在可以用Simple2作为类型声明新的结构体变量
Simple2 u1, u2[20], *u3;

void struct_define_init()
{
    struct Books
    {
        char title[50];
        char author[50];
        char subject[100];
        int book_id;
    } book = {"C 语言", "RUNOOB", "编程语言", 123456};
    printf("书名: %s, 作者: %s, 主题: %s, 书号: %d\n", book.title, book.author, book.subject, book.book_id);

    struct Books book2 = {"Java 语言", "JJJJJ", "编程语言", 123457};
    printf("书名: %s, 作者: %s, 主题: %s, 书号: %d\n", book2.title, book2.author, book2.subject, book2.book_id);

    struct Books book3;
    strcpy(book3.title, "Python 语言");
    strcpy(book3.author, "AAAAA");
    strcpy(book3.subject, "编程语言");
    book3.book_id = 123458;
    printf("书名: %s, 作者: %s, 主题: %s, 书号: %d\n", book3.title, book3.author, book3.subject, book3.book_id);
}

int main()
{
    // 可以使用 sizeof 运算符来计算结构体的大小，sizeof 返回的是给定类型或变量的字节大小。
    // 对于结构体，sizeof 将返回结构体的总字节数，包括所有成员变量的大小以及可能的填充字节。
    // 结构体的大小可能会受到编译器的优化和对齐规则的影响，编译器可能会在结构体中插入一些额外的填充字节以对齐结构体的成员变量，以提高内存访问效率。因此，结构体的实际大小可能会大于成员变量大小的总和。
    // s1: 4(int) + 1(char) + 8(double) = 13 < 16
    printf("s1 size: %ld\n", sizeof(s1));
    printf("char size: %ld\n", sizeof(char));
    printf("int size: %ld\n", sizeof(int));
    printf("double size: %ld\n", sizeof(double));
    s1.a = 10;
    s1.b = 'a';
    s1.c = 3.14;
    printf("s1 init size: %ld\n", sizeof(s1));
    printf("s1.a = %d, s1.b = %c, s1.c = %f\n", s1.a, s1.b, s1.c);

    struct SIMPLE s2; // 使用结构体标签定义变量必须带struct关键字
    s2.a = 20;
    s2.b = 'b';
    s2.c = 6.28;
    printf("s2.a = %d, s2.b = %c, s2.c = %f\n", s2.a, s2.b, s2.c);

    t1.a = 10;
    t1.b = 'a';
    t1.c = 3.14;
    printf("t1.a = %d, t1.b = %c, t1.c = %f\n", t1.a, t1.b, t1.c);

    SIMPLE2 s3; // 使用typedef定义的类型，进行结构体变量定义时无需带struct关键字
    s3.a = 30;
    s3.b = 'c';
    s3.c = 9.87;
    printf("s3.a = %d, s3.b = %c, s3.c = %f\n", s3.a, s3.b, s3.c);

    // 指针不能直接赋值，需要先申请空间，不然程序执行卡死
    u3 = (Simple2 *)malloc(sizeof(Simple2));
    u3->a = 40; // 不申请内存直接赋值，卡死
    u3->b = 'd';
    u3->c = 12.34;
    printf("u3->a = %d, u3->b = %c, u3->c = %f\n", u3->a, u3->b, u3->c);
    free(u3);

    struct_define_init();
    return 0;
}