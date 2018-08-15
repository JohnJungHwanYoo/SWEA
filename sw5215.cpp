// SWEA 5215. 햄버거 다이어트

#include<stdio.h>
#include<stdlib.h>

int test_case;
int N, L;
int T_arr[22];
int K_arr[22];
int cur_taste, MX_taste;

void init(void)
{
	cur_taste = 0;
	MX_taste = 0;
	return;
}

void Recursion(int lastidx,int cur_cal)
{
	for (int i = lastidx + 1; i < N; i++)
	{
		if (cur_cal + K_arr[i] <= L)
		{
			cur_taste = cur_taste + T_arr[i];
			cur_cal = cur_cal + K_arr[i];
			//printf("cur_taste : %d cur_cal: %d\n", cur_taste, cur_cal);
			if (cur_taste > MX_taste)
				MX_taste = cur_taste;
			Recursion(i, cur_cal);
			cur_cal = cur_cal - K_arr[i];
			cur_taste = cur_taste - T_arr[i];
		}
		else
		{
			cur_cal + K_arr[i];
			Recursion(i, cur_cal);
			cur_cal - K_arr[i];

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
		scanf("%d %d", &N, &L);
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &T_arr[i], &K_arr[i]);
		}

		Recursion(-1,0);
		printf("#%d %d\n", tc, MX_taste);
	}
	return 0;
}
