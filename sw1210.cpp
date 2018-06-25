// 1210. [S/W 문제해결 기본] 2일차 - Ladder1 D4

#include<stdio.h>

int board[102][102];

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		int test_case = 0;
		scanf("%d", &test_case);
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				scanf("%d", &board[i][j]);
			}
		}

		int start_point = 0;
		for (int i = 0; i < 100; i++)
		{
			if (board[99][i] == 2)
			{
				start_point = i;
				break;
			}
		}
		int state = 0;
		int row = 99;
		int col = start_point;

		while (row != 0)
		{
			if(board[row][col-1]==1)
			{ 
				//printf("@ row:%d, col:%d\n",row,col);
				state = -1;
				while (board[row][col-1] != 0)
				{
					col = col + state;
				}
				state = 0;
				row--;
			}
			else if (board[row][col + 1] == 1)
			{
				//printf("# row:%d, col:%d\n", row, col);
				state = 1;
				while (board[row][col+1] != 0)
				{
					col = col + state;
				}
				row--;
				state = 0;
			}
			else 
			{
				//printf("$ row:%d, col:%d\n", row, col);
				row--;
			}


		}

		printf("#%d %d\n", test_case, col);
	}
	return 0;
}
