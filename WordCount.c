#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
#include<io.h>
#pragma warning(disable:4996)
int main(int argc, char* argv[]) {
    char bet;
    FILE* f;
    if (argc < 3 || argc>3)
    {
        printf("1.输入参数错误");
        return -1;
    }
    f = fopen(argv[2],"r");
    assert(f!=0);
    if (strcmp(argv[1],"-c")==0)
    {
        bet = 'c';
    }
    else if (strcmp(argv[1], "-w") == 0)
    {
        bet = 'w';
    }
    else 
    {
        printf("2.输入参数错误");
        return -1;
    }
    func(bet, argv[2]);
    return 0;
}
int func(char ch,char* p)
{
    FILE* f=fopen(p,"r");
    char bet;
    int num = 0;
    int is_word = 0;
    if (ch == 'w')
    {
        while (!feof(f))
        {
            bet = fgetc(f);
            if ((bet >= 'a' && bet <= 'z') || (bet >= 'A' && bet <= 'Z') || bet == '_')
                is_word = 1;
            else
            {
                num++;
                is_word = 0;
            }
        }
        printf("单词数：%d\n",num);
    }
    else if(ch =='c')
    {
        while (!feof(f))
        {
            bet = fgetc(f);
            if ((bet==' ')||(bet=='\n')||(bet=='\t'))
                num++;
        }
        printf("字符数：%d",num);
    }
    return 0;
}

