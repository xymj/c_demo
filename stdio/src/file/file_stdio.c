#include <stdio.h>

int main(int argc, char const *argv[])
{

    // fopen() 函数用于打开一个文件。
    // 参数：filename：要打开的文件名。
    //      mode：打开文件的模式，如 "r"（只读）、 "w"（只写）、 "a"（追加）等。
    // 返回值：
    //      成功时返回指向FILE对象的指针，失败时返回NULL。 return 0;
    FILE *fp = fopen("file_test.txt", "w");
    if (fp != NULL)
    {
        fprintf(fp, "test write file!\n");
        // fputs("test write file!\n", fp);
        fflush(fp); // 刷新缓冲区确保数据写入文件
        fclose(fp);
    }

    char str[100];
    fp = fopen("file_test.txt", "r");
    if (fp != NULL)
    {
        fgets(str, 100, fp);
        printf("fgets: %s\n", str);
        fscanf(fp, "%s", str);
        printf("fscanf: %s\n", str);
        fclose(fp);
    }

    return 0;
}
