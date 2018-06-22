//3304. 최장 공통 부분

#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>

using namespace std;

int test_case;
int dp[1002][1002];


int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		char a[1002] = {};
		char b[1002] = {};
		scanf("%s %s", a,b);
		int len_a = strlen(a);
		int len_b = strlen(b);

		for (int i = 1; i <= len_a; i++)
		{
			for (int j = 1; j <= len_b; j++)
			{
				if (a[i - 1] == b[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		printf("#%d %d\n", i + 1, dp[len_a][len_b]);
	}
	return 0;
}
