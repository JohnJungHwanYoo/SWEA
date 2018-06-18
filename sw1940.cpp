//1940. 가랏! RC카!

#include<stdio.h>

int test_case;

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int sec;
		int dis[32] = {};
		scanf("%d", &sec);
		int sum = 0;
		for (int j = 1; j <= sec; j++)
		{
			int cmd = 0;
			int acc = 0;
			scanf("%d", &cmd);
			if (cmd == 1)
			{
				scanf("%d", &acc);
				dis[j] = dis[j - 1] + acc;
			}
			else if(cmd == 2)
			{
				scanf("%d", &acc);
				dis[j] = dis[j - 1] - acc;
				if (dis[j] < 0) dis[j] = 0;
			}
			else dis[j] = dis[j - 1];
			sum = sum + dis[j];
		}
		printf("#%d %d\n", i + 1, sum);
	}
	return 0;
}
