#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
#include<io.h>
#pragma warning(disable:4996)
int CodeCount(char* p);
int WordCount(char* p);
int main(int argc, char* argv[]) {
    char bet;
    FILE* f;
    //参数输入
    if (argc < 3 || argc>3)
    {
        printf("1.输入参数错误");
        return -1;
    }
    f = fopen(argv[2], "r");
    assert(f != 0);
    if (strcmp(argv[1], "-c") == 0)
        bet = 'c';
    else if (strcmp(argv[1], "-w") == 0)
        bet = 'w';
    else
    {
        printf("2.输入参数错误");
        return -1;
    }
    //打印结果
    switch (bet) {
    case 'c':printf("字符数：%d\n", WordCount(bet, argv[2])); break;
    case 'w':printf("字符数：%d\n", CodeCount(bet, argv[2])); break;
    default:break;
    }
    return 0;
}
int WordCount(char* p)//单词统计
{
    FILE* f = fopen(p, "r");
    char bet;
    int num = 0;
    while (!feof(f))
    {
        bet = fgetc(f);
        if ((bet != ' ') && (bet != '\n') && (bet != '\t'))//判断是否是单词
            num++;
    }
    return num;
}
int CodeCount(char* p)//字符统计
{
    FILE* f = fopen(p, "r");
    char bet;
    int num = 0;
    int is_code = 0;//字符状态
    while (!feof(f))
    {
        bet = fgetc(f);
        if ((bet >= 'a' && bet <= 'z') || (bet >= 'A' && bet <= 'Z'))//判断是否是字符
        {
            is_code = 1;
            num++;
        }
        else
            is_code = 0;
    }
    return num;
}
