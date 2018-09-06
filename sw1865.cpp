//SWEA 1865. 동철이의 일 분배

#include<stdio.h>

int test_case;
int N;
double probability[18][18];
int isUsed[18];
double MX;

void init()
{
	MX = 0;
	for (int i = 0; i < 16; i++)
	{
		isUsed[i] = 0;
		for (int j = 0; j < 16; j++)
		{
			probability[i][j] = 0;
		}
	}
	return;
}

void Recursion(int depth,double cur_prob)
{
	if (cur_prob*100 <= MX)return;
	if (depth == N)
	{
		if (cur_prob*100 > MX)
		{
			MX = cur_prob * 100;
		}
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (isUsed[i] == 1)continue;
		isUsed[i] = 1;
		Recursion(depth + 1,cur_prob * probability[depth][i]);
		isUsed[i] = 0;
	}
	return;
}

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		init();
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%lf", &probability[i][j]);
				probability[i][j] = probability[i][j] / 100;
			}
		}

		Recursion(0,1);
		printf("#%d %lf\n", tc, MX);
	}
	return 0;
}
