//1215. [S/W 문제해결 기본] 3일차 - 회문1

#include<stdio.h>
#include<string>
#include<string.h>

char board[9][9];

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		int check_len = 0;
		scanf("%d", &check_len);
		for (int j = 0; j < 8; j++)
		{
			scanf("%s", board[j]);
		}
		//for (int j = 0; j < 8; j++)
		//{
		//	for (int k = 0; k < 8; k++)
		//	{
		//		printf("%c ", board[j][k]);
		//	}
		//	printf("\n");
		//}

		int check_num = check_len / 2;
		int cnt = 0;
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8-check_len+1; k++)
			{
				for (int l = 0; l < check_num; l++)
				{
					if (board[j][k + l] != board[j][k + (check_len - 1) - l]) break;
					if (l == (check_num - 1))
					{
						//printf("** j:%d k:%d\n", j, k);
						cnt++;
					}
				}

				for (int l = 0; l < check_num; l++)
				{
					if (board[k + l][j] != board[k + (check_len - 1) - l][j]) break;
					if (l == (check_num - 1))
					{
						cnt++;
						//printf("@@j:%d k:%d\n", j, k);
					}
				}
			}
		}
		printf("#%d %d\n", i + 1, cnt);
	}
	return 0;
}
