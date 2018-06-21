//1928. Base64 Decoder

#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>

using namespace std;

int test_case;	
char Encoding_board[65];

char input[100002] = {};
int input_6[100002];
char output[100002] = {};
int bin[600002] = {};

int wordcheck(char a)
{
	for (int i = 0; i < 64; i++)
	{
		if (a == Encoding_board[i])
		{
			//printf("%d\n", i);

			return i;
		}
	}
}


int main(void)
{
	//Encoding Board 만들기
	for (int j = 0; j < 26; j++)
	{
		Encoding_board[j] = 'A' + j;
		Encoding_board[j + 26] = 'a' + j;
	}
	for (int j = 0; j < 10; j++)
	{
		Encoding_board[j+52] = '0' + j;
	}
	Encoding_board[62] = '+';
	Encoding_board[63] = '/';
	//Encoding Board 만들기 종료


	//for (int i = 0; i < 64; i++)
	//{
	//	printf("%c", Encoding_board[i]);
	//}

	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{

		scanf("%s", input);
		int len = strlen(input);


		for (int i = 0; i < len; i++)
		{
			input_6[i] = wordcheck(input[i]);
		}

		int cnt = 0;
		for (int j = 0; j < len; j++)
		{
			for (int k = 5; k >= 0; k--)
			{
				if (input_6[j] & (1 << k)) bin[cnt] = 1;
				else bin[cnt] = 0;
				//printf("%d", bin[cnt]);
				cnt++;

			}
			//printf("%d", input_6[j]);
		}

		//for (int i = 0; i < cnt; i++)
		//{
		//	printf("%d", bin[i]);
		//}
		//6byte 입력 완료

		//8byte 출력을 위한 작업 시작
		int output_cnt = 0;
		for (int i = 7; i < cnt; i = i + 8)
		{
			int bin_sum = 0;
			for (int j = 0; j <= 7; j++)
			{
				bin_sum = bin_sum + bin[i - j] * pow(2, j);
				//printf("%d\n", bin_sum);
				
			}
			output[output_cnt] = (char)bin_sum;
			output_cnt++;
		}
		printf("#%d %s\n", i + 1, output);
		fill(input,input+len,0);
		fill(input_6, input_6 + len, 0);
		fill(bin, bin + cnt, 0);
		fill(output, output + output_cnt, 0);

	}
	return 0;
}
