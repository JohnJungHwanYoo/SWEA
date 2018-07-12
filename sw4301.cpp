//4301. 콩 많이 심기 D4

#include<stdio.h>

int test_case;
int N, M;
int map[1002][1002];
int isVisited[1002][1002];
int cnt;

void init(void)
{
	cnt = 0;
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			map[i][j] = 0;
			isVisited[i][j] = 0;
		}
	}
	return;
}

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		init();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (isVisited[i][j] == 0 && map[i][j] == 0)
				{
					map[i][j] = 1;
					isVisited[i][j] = 1;
					cnt++;
					if (i + 2 < N) 
					{
						map[i + 2][j] = 2;
						isVisited[i + 2][j] = 1;
					}
					if (j + 2 < M)
					{
						map[i][j + 2] = 2;
						isVisited[i][j + 2] = 1;
					}
				
				}
				//for (int i = 0; i < N; i++)
				//{
				//	for (int j = 0; j < M; j++)
				//	{
				//		printf("%d ", map[i][j]);
				//	}
				//	printf("\n");
				//}
				//printf("i:%d j:%d\n", i, j);
				//printf("\n");

			}
		}
		printf("#%d %d\n", tc, cnt);

	}
	return 0;
}
