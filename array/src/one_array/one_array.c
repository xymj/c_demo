#include <stdio.h>

// 宏定义计算数组长度
#define LENGTH(array) (sizeof(array) / sizeof(array[0]))

// main后定义函数，必须先函数声明
void array_define();

void array_length();

void array_ptr();

int main()
{
    // 声明数组、数组赋值、访问数组
    array_define();

    // 数组长度可以使用 sizeof 运算符来获取数组的长度
    array_length();

    // 数组名本身是一个常量指针，意味着它的值是不能被改变的，一旦确定，就不能再指向其他地方。
    array_ptr();
}

void array_define()
{
    int arr[10];
    int i, j;
    for (i = 0; i < 10; i++)
    {
        arr[i] = i + 1000;
    }
    for (j = 0; j < 10; j++)
    {
        printf("arr[%d]: %d\n", j, arr[j]);
    }
}

void array_length()
{
    int numbers[] = {1, 2, 3, 4, 5};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    printf("numbers length: %d\n", length);

    char chars[] = "hello"; // 包含'\0'结尾符
    int chars_length = LENGTH(chars);
    printf("use define LENGTH chars length: %d\n", chars_length);

    double doubles[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int doubles_length = LENGTH(doubles);
    printf("use define LENGTH doubles length: %d\n", doubles_length);
}

// 当数组作为参数传递给函数时，它会退化为指针，失去其大小信息。因此无法通过指针直接获取原数组的大小，需要将数组大小作为额外参数传递
/**
下述函数内都不能使用LENGTH宏获取大小，原因如下：
1. 在C语言中，当数组作为参数传递给函数时，会发生数组到指针的转换（array-to-pointer decay）。
2. 这意味着无论你在参数声明中写的是：
   - `int arr[]`
   - `int arr[5]`
   - `int *arr`
   它们在函数内部都是等价的，都只是一个指向`int`的指针，不包含任何关于原数组大小的信息。
 */
void printArray(int arr[], int size);
void printArray1(int *arr, int size);
void printArray2(int arr[5], int size);

void array_ptr()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    printf("arr: %p\n", arr);
    printf("ptr: %p\n", ptr);
    printf("ptr value: %d\n", *ptr);
    int *ptr0 = &arr[0]; // ptr0 指针变量被初始化为 array 的地址，即数组的第一个元素的地址。
    printf("ptr0: %p\n", ptr0);
    printf("&arr[0]: %p\n", &arr[0]);
    printf("ptr0 value: %d\n", *ptr0);

    // 虽然数组名表示数组的地址，但在大多数情况下，数组名会自动转换为指向数组首元素的指针。这意味着我们可以直接将数组名用于指针运算，例如在函数传递参数或遍历数组时：
    printArray(arr, 5);
    printArray1(arr, 5);
    printArray2(arr, 5);
}

// 传递数组给函数,形式参数是一个未定义大小的数组：
void printArray(int arr[], int size)
{
    printf("printArray: ");
    // int size = LENGTH(arr); error!!
    // 注意：在函数内部，arr是一个指针（尽管声明为int arr[]，但它实际上是指向int的指针），而LENGTH宏需要一个真正的数组才能工作。
    // 当数组作为参数传递给函数时，它会退化为指针，失去了大小信息。
    // 正确的做法是使用传入的size参数。
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 传递数组给函数,形式参数是一个指针
void printArray1(int *arr, int size)
{
    // int size = LENGTH(*arr); error!!  `arr`是一个指向`int`类型的指针,`*arr`是对指针解引用，得到的是数组第一个元素的值（一个`int`类型
    // 值），而不是整个数组, `LENGTH(*arr)`试图将一个`int`值作为数组传入宏，这会导致编译错误

    printf("printArray1: ");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 传递数组给函数,形式参数是一个已定义大小的数组：
void printArray2(int arr[5], int size)
{
    printf("printArray2: ");
    // 即使在参数声明中指定了数组大小（int arr[5]），在函数内部它仍然被视为指针，
    // 无法使用LENGTH宏来获取数组大小。
    // int len = LENGTH(arr); // 这样做是错误的！

    // 正确的做法是使用传入的size参数
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
