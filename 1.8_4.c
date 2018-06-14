#if 0
编写一个程序，一行行地读取输入行，直至到达文件尾。
算出每行输入行的长度，然后把最长的那行打印出来。
为了简单起见，你可以假定所有的输入行均不超过1000个字符。
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


