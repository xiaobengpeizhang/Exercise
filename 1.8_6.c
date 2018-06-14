/*
**去除输入中列标号的个数必须是偶数的限制，
如果是奇数，则最后一个列标号到该行行末将被复制
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20 /*max number that columns array can contain*/
#define MAX_INPUT 1000

int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input, int n_columns, int const columns[]);

int main(void)
{
    int Case, If, While, Stop, stop;
    int n_columns;  /**/
    int columns[MAX_COLS];  /*a array contain column number*/
    char input[MAX_INPUT];  /*input line*/
    char output[MAX_INPUT]; /*output line to show*/
    n_columns = read_column_numbers(columns, MAX_COLS);

    while(gets(input) != NULL){
        printf("Original input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s\n", output);
    }

    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
    int num = 0;    /*useful number of columns to handle*/
    int ch;

    while(num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
        num += 1;
#if 0
    if(num % 2 != 0){
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }
#endif // 0

    while((ch = getchar()) != EOF && ch != '\n')
        ;
    return num;
}

void rearrange(char *output, char const *input, int n_columns, int const columns[])
{
    int col;
    int output_col;
    int len;

    len = strlen(input);
    output_col = 0;

    for(col = 0; col < n_columns; col += 2){

        int begin = columns[col];
        if(begin >= len || output_col == MAX_INPUT - 1)
            break;

        int minus;
        if(col >= n_columns - 1){
            minus = len - 1 - begin;
        }else{
            minus = columns[col + 1] - begin;
        }


        if(minus < 0){
            minus = -minus;
            begin = columns[col + 1];
        }
        int nchars =  minus + 1;



        if(output_col + nchars > MAX_INPUT - 1)
            nchars = MAX_INPUT - 1 - output_col;

        /*
        **do copy
        */
        strncpy(output + output_col, input + begin, nchars);
        output_col += nchars;

    }
    output[output_col] = '\0';
}
#

#if 0
another solution （I think it's not precise

/* ** Process a line of input by concatenating the characters from the indicated ** columns. The output line is then NUL terminated. */
void rearrange( char *output, char const *input, int const n_columns, int const columns[] )
{
    int col; /* subscript for columns array */
    int output_col; /* output column counter */
    int len; /* length of input line */
    len = strlen( input );
     output_col = 0;
/* ** Process each pair of column numbers. */
    for( col = 0; col < n_columns; col += 2 ){

        int nchars;
        if(columns[col] >= len || output_col == MAX_INPUT - 1){
            break;
        }
/* ** Compute how many characters to copy. */
        if(col + 1 < n_columns){
            nchars = columns[col + 1] - columns[col] + 1;
        }else{
            nchars = len - columns[col + 1];
        }
/* ** If there isn’t room in the output array, only copy what will ** fit. */
        if(output_col + nchars > MAX_INPUT - 1)
            nchars = MAX_INPUT - output_col - 1;
/* ** Copy the relevant data.
        */
        strncpy( output + output_col, input + columns[col], nchars );
        output_col += nchars;
    }
    output[output_col] = '\0';
}
#endif // 0
