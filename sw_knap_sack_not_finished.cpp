// 0/1 Knapsack











/* runtime error



#include<stdio.h>
#include<algorithm>

using namespace std;

int test_case;
int vc[2][1002] = {};

int Max;
int N, K;
int v_sum;
int c_sum;


int Recursive(int K, int lastidx)
{
	if (v_sum == K)
	{
		if (c_sum >= Max)
		{
			Max = c_sum;
		}
	}
	for (int i = lastidx+1; i < N; i++)
	{
		if (v_sum + vc[0][i] > K)continue;
		v_sum = v_sum + vc[0][i];
		c_sum = c_sum + vc[1][i];
		Recursive(K, i);
		v_sum = v_sum - vc[0][i];
		c_sum = c_sum - vc[1][i];
	}
	return 0;
}

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d %d", &N, &K);
		for (int j = 0; j < N; j++)
		{
			scanf("%d %d", &vc[0][j], &vc[1][j]);
		}
		Max = 0;
		v_sum = 0;
		c_sum = 0;

		Recursive(K,-1);

		printf("#%d %d\n", i + 1, Max);
	}
	return 0;
}

*/
