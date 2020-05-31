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
    //��������
    if (argc < 3 || argc>3)
    {
        printf("1.�����������");
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
        printf("2.�����������");
        return -1;
    }
    //��ӡ���
    switch (bet) {
    case 'c':printf("�ַ�����%d\n", WordCount(bet, argv[2])); break;
    case 'w':printf("�ַ�����%d\n", CodeCount(bet, argv[2])); break;
    default:break;
    }
    return 0;
}
int WordCount(char* p)//����ͳ��
{
    FILE* f = fopen(p, "r");
    char bet;
    int num = 0;
    while (!feof(f))
    {
        bet = fgetc(f);
        if ((bet != ' ') && (bet != '\n') && (bet != '\t'))//�ж��Ƿ��ǵ���
            num++;
    }
    return num;
}
int CodeCount(char* p)//�ַ�ͳ��
{
    FILE* f = fopen(p, "r");
    char bet;
    int num = 0;
    int is_code = 0;//�ַ�״̬
    while (!feof(f))
    {
        bet = fgetc(f);
        if ((bet >= 'a' && bet <= 'z') || (bet >= 'A' && bet <= 'Z'))//�ж��Ƿ����ַ�
        {
            is_code = 1;
            num++;
        }
        else
            is_code = 0;
    }
    return num;
}
