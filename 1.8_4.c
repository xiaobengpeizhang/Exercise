#if 0
��дһ������һ���еض�ȡ�����У�ֱ�������ļ�β��
���ÿ�������еĳ��ȣ�Ȼ���������д�ӡ������
Ϊ�˼����������Լٶ����е������о�������1000���ַ���
#endif

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1001
/*
**define max and refresh max if it's necessary
*/

int main(void)
{
    char longest[MAX_LEN];
    int longest_len = -1;
    char input[MAX_LEN];
    int input_len;

    while(gets(input) != NULL){
        input_len = strlen(input);
        if(input_len > longest_len){
            longest_len = input_len;
            strcpy(longest, input);
        }
    }

    if(longest_len >= 0){
        puts(longest);
    }

    return EXIT_SUCCESS;
}

#if 0
1 note the number meaning
2 note the situtation that nothing to input
#endif // 0


