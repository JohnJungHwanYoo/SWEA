//1215. [S/W 문제해결 기본] 3일차 - 회문1

#include<stdio.h>
#include<string>
#include<string.h>

char board[101][101];

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		int test_case = 0;
		scanf("%d", &test_case);
		for (int j = 0; j < 100; j++)
		{
			scanf("%s", board[j]);
		}
		int check_len = 100;

		bool state = false;
		int cur_max = 0;
		int ans = 0;

		for (int j = 100; j > 0; j--)//length
		{
			int loop = j / 2;

			for (int i = 0; i < 100; i++)//행
			{
				for (int k = 0; k < 100 - j + 1; k++)
				{
					for (int l = 0; l < loop; l++)
					{
						if (board[i][k + l] != board[i][k + (j - 1) - l])break;
						if (l == (loop - 1))
						{
							//printf("&&i:%d k:%d \n", i, k);
							ans = j;
							state = true;
							break;
						}
						if (state == true)break;

					}
					if (state == true)break;
					for (int l = 0; l < loop; l++)
					{
						if (board[k + l][i] != board[k + (j - 1) - l][i])break;
						if (l == (loop - 1))
						{
							//printf("**i:%d k:%d \n", i, k);
							ans = j;
							state = true;
							break;
						}
						if (state == true)break;

					}
					if (state == true)break;

				}
				if (state == true)break;

			}
			if (state == true)break;

		}
		printf("#%d %d\n", i + 1, ans);
	}
	return 0;
}
