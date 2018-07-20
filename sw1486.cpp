//1486. 장훈이의 높은 선반 D4


#include<stdio.h>

int test_case;
int N_arr[22];
int N;
int B;
int cur_min = 999999;

void init(void)
{
	cur_min = 999999;
	return;
}

int Recursion(int B, int cur_sum, int last_idx)
{
	if (cur_sum >= B)
	{
		//printf("cur_sum:%d\n", cur_sum);
		if (cur_sum <= cur_min) cur_min = cur_sum;
		//printf("cur_min:%d\n", cur_min);
		return 0;
	}
	for (int i = last_idx+1; i < N; i++)
	{
		cur_sum = cur_sum + N_arr[i];
		//printf("%d\n", cur_sum);
		Recursion(B, cur_sum, i);
		cur_sum = cur_sum - N_arr[i];
	}
	return 0;
}

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		init();
		scanf("%d %d", &N, &B);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &N_arr[i]);
		}

		Recursion(B, 0,-1);
		//printf("%d \n", cur_min);
		printf("#%d %d\n", tc, cur_min - B);
	}
	return 0;
}
