//3752. 가능한 시험 점수 D4

#include<stdio.h>

int test_case;
int N, sum;
int score[102];
bool possible_score_check[10200];

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d", &N);
		sum = 0;
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &score[j]);
			sum += score[j];
		}
		//printf("%d \n", sum);
		possible_score_check[0] = true;
		for (int j = 0; j < N; j++)
		{
			for (int k = sum; k >= 0; k--)
			{
				if (possible_score_check[k] == true)
				{
					possible_score_check[k + score[j]] = true;
				}
			}
		}
		int ans = 0;
		for (int l = 0; l < 10101; l++)
		{
			if (possible_score_check[l] == true)ans++;
		}
		printf("#%d %d\n", i + 1, ans);
		for (int i = 0; i < 101; i++)
		{
			score[i] = 0;
		}
		for (int i = 0; i < 10101; i++)
		{
			possible_score_check[i] = false;
		}
	}
	return 0;
}
