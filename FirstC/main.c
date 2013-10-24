// FirstC.cpp : Defines the entry point for the console application.
// 这个程序从标准输入中读取输入行并在标准输出中打印这些输入行
// 每个输入行的后边是该行内容的一部分

// 输入的第一行是一串列标号，串的最后一位以一个复数结尾
// 这些列标号成对出现，书名需要打印的输入行的列标范围
// 例如，0 3 10 12 -1表示第零列到第三列，第十列到第十三咧的内容将被打印

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_INPUT 1000                  // 每个输入行的最大长度

int read_column_numbers( int columns[], int max);
void rearrange( char *output, char const *input,
				int n_columns, int const columns[]);


int main()
{
	int n_columns;
	int columns[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];

	// 读取该串的列标号
	n_columns = read_column_numbers( columns, MAX_COLS);

	// 读取、处理和打印剩余的输入行
	while( gets(input) != NULL)
	{
		printf("Original input : %s\n", input);
		rearrange( output, input, n_columns, columns);
		printf("Rearrange input : %s\n", output);
	}

	return EXIT_SUCCESS;
	// return 0;
}

// 读取列标号，如果超出规定范围则不予理会
int read_column_numbers( int columns[], int max)
{
	int num = 0;
	int ch;

	while( (num < max) && (scanf("%d", &columns[num]) == 1)
						&& (columns[num] > 0))
	{
		num += 1;
	}

	if ( num % 2 != 0)
	{
		puts( "Last columns number is not paired.");
		exit( EXIT_FAILURE );
	}

	while ( ((ch = getchar()) != EOF) && (ch != '\n') )
		;

	return num;

}

// 处理输入行，将制定列的字符连接在一起，输入行以NULL结尾
void rearrange( char *output, char const *input,
				int n_columns, int const columns[])
{
	int col;
	int output_col;
	int len;

	len = strlen( input );
	output_col = 0;

	for ( col = 0; col < n_columns; col +=2 )
	{
		int nchars = columns[col + 1] - columns[col] + 1;

		if ( (columns[col] >= len ) || output_col == MAX_INPUT - 1)
			break;

		if ( output_col + nchars > MAX_INPUT - 1 )
		{
			nchars = MAX_INPUT - output_col -1;
		}

		strncpy( output + output_col, input + columns[col], nchars);
		output_col += nchars;

	}
	output[output_col] = '\0';

}

