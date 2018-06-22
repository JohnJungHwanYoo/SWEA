//3282. 0/1 Knapsack

#include<stdio.h>
#include<algorithm>
#include<functional>

using namespace std;

int test_case;
//N(1≤N100)개
//최대 K(1≤K≤1000) 부피
int N, K;
int vi[102];
int ci[102];
int dp[1002][102];

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d %d", &N, &K);
		for (int j = 1; j <= N; j++)
		{
			scanf("%d %d", &vi[j], &ci[j]);
		}
		
		for (int i = 1; i <= K; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i >= vi[j])dp[i][j] = max(dp[i][j - 1], dp[i - vi[j]][j - 1] + ci[j]);
				else dp[i][j] = dp[i][j - 1];
			}
		}
		printf("#%d %d\n", i + 1, dp[K][N]);
		

		//Initialization is not completed.
		//It is okay not to initialize again.
	}
	return 0;
}
