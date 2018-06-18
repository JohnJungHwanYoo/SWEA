//1954. 달팽이 숫자

#include<stdio.h>

int test_case;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int N;
		scanf("%d", &N);
		int isVisited[12][12] = {};
		int board[12][12] = {};
		int new_x = 0;
		int new_y = 0;
		int cnt = 1;
		int state = 0;

		do
		{
			board[new_x][new_y] = cnt;
			isVisited[new_x][new_y] = 1;
			cnt++;
			new_x = new_x + dx[state];
			new_y = new_y + dy[state];
			if (new_x >= N || new_x < 0 || new_y >= N || new_y < 0 || isVisited[new_x][new_y]==1)
			{
				new_x = new_x - dx[state];
				new_y = new_y - dy[state];
				state++;
				state = state % 4;
				new_x = new_x + dx[state];
				new_y = new_y + dy[state];
			}
			/*for (int l = 0; l < N; l++)
			{
				for (int m = 0; m < N; m++)
				{
					printf("%d ", board[l][m]);
				}
				printf("\n");
			}*/
		} while (cnt != N*N+1);
		printf("#%d\n", i + 1);
		for (int l = 0; l < N; l++)
		{
			for (int m = 0; m < N; m++)
			{
				printf("%d ", board[l][m]);
			}
			printf("\n");
		}

	}
	return 0;
}
