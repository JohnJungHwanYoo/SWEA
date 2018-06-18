#include<stdio.h>
#include<string>
#include<string.h>

using namespace std;


int test_case;
int dx[9] = {0,-1,0,1,1,1,0,-1,-1};
int dy[9] = {0,1,1,1,0,-1,-1,-1,0};

int board_check(int*state)
{
	for (int i = 1; i <= 9; i++)
	{
		if (state[i] == 0) return 0;
	}
	return 1;
}

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int board[10][10] = {};
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				scanf("%d", &board[j][k]);
			}
		}
		//가로,세로 체크
		int state_1[10] = {};
		int state_2[10] = {};
		for (int j = 0; j < 9; j++)
		{
			fill(state_1, state_1 + 10, 0);
			fill(state_2, state_2 + 10, 0);
			for (int k = 0; k < 9; k++)
			{
				state_1[board[j][k]] = 1;
				state_2[board[k][j]] = 1;
			}
			if (board_check(state_1) == 0)
			{
				printf("#%d %d\n", i + 1, 0);
				break;
			}
			if (board_check(state_2) == 0)
			{
				printf("#%d %d\n", i + 1, 0);
				break;
			}

		}
		int state_3[10] = {};

		for (int l = 1; l < 9; l=l+3)
		{
			for (int m = 1; m < 9; m = m + 3)
			{
				fill(state_3, state_3 + 10, 0);
				for (int dir = 0; dir < 9; dir++)
				{
					int new_x = l + dx[dir];
					int new_y = m + dy[dir];
					state_3[board[new_x][new_y]] = 1;

				}
				if (board_check(state_3) == 0)
				{
					printf("#%d %d\n", i + 1, 0);
					break;
				}
			}
			if (board_check(state_3) == 0) break;
		}
		if(board_check(state_1)==1 && board_check(state_2)==1 && board_check(state_3) ==1)
		{
			printf("#%d %d\n", i + 1, 1);
		}
	}
	return 0;

}



