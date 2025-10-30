#include <stdio.h>

void array_ptr_2d();

int main()
{
    // 二维数组遍历示例
    int num[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("num[0][0]: %d\n", num[0][0]);
    printf("*num: %p\n", *num);
    printf("**num value: %d\n", **num);

    array_ptr_2d();
}

// 二维数组遍历函数声明
void print2DArray1(int arr[][3], int rows);
void print2DArray2(int (*arr)[3], int rows);
void print2DArray3(int *arr[], int rows);
void print2DArray4(int **arr, int rows, int cols);

void array_ptr_2d()
{

    int num[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // 方式1: 传递二维数组本身（需要指定列数）
    print2DArray1(num, 2);

    // 方式2: 传递指向数组的指针
    print2DArray2(num, 2);

    // 方式3: 传递数组指针的数组（需要重新组织数据）
    int *arr[2];
    for (int i = 0; i < 2; i++)
    {
        arr[i] = num[i];
    }
    print2DArray3(arr, 2);

    // 方式4: 传递双重指针（需要重新组织数据）
    int *ptr[2];
    for (int i = 0; i < 2; i++)
    {
        ptr[i] = num[i];
    }
    print2DArray4(ptr, 2, 3);
}

// 方式1: 传递二维数组本身（需要指定列数）
// 在函数参数中，int arr[][3] 等价于 int (*arr)[3]
// 这种方式要求在编译时知道列数，行数可以作为参数传递
void print2DArray1(int arr[][3], int rows)
{
    printf("方式1 - 传递二维数组本身（int arr[][3]）:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// 方式2: 传递指向数组的指针
// int (*arr)[3] 明确表示arr是一个指向包含3个int元素的数组的指针
void print2DArray2(int (*arr)[3], int rows)
{
    printf("方式2 - 传递指向数组的指针（int (*arr)[3]）:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]); // 也可以写成 *(*(arr+i)+j)
        }
        printf("\n");
    }
}

// 方式3: 传递数组指针的数组
// int *arr[] 表示arr是一个数组，其中每个元素都是指向int的指针
void print2DArray3(int *arr[], int rows)
{
    printf("方式3 - 传递数组指针的数组（int *arr[]）:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]); // 也可以写成 *(*(arr+i)+j)
        }
        printf("\n");
    }
}

// 方式4: 传递双重指针
// int **arr 表示arr是一个指向指针的指针，这个指针又指向int
void print2DArray4(int **arr, int rows, int cols)
{
    printf("方式4 - 传递双重指针（int **arr）:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]); // 也可以写成 *(*(arr+i)+j)
        }
        printf("\n");
    }
}
