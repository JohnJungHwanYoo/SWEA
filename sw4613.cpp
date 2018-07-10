//4613. 러시아 국기 같은 깃발 D4

#include<stdio.h>
#include<string>
#include<string.h>

using namespace std;

int test_case;
int N, M;
char flag[52][52];
int ans = 9999;
int cur_cnt;

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++)
		{
			scanf("%s", flag[i]);
		}

		for (int i = 1; i <= N - 2; i++)
		{
			for (int j = 1; j <= N - i - 1; j++)
			{
				int k = N - i - j;
					cur_cnt = 0;
					for (int l = 1; l <= N; l++)
					{
						for (int m = 0; m < M; m++)
						{
							if (l <= i)
							{
								if (flag[l][m] != 'W')cur_cnt++;
							}
							if (l > i && l <= (i + j))
							{
								if (flag[l][m] != 'B')cur_cnt++;
							}
							if (l > (i + j) && l <= (i + j + k))
							{
								if (flag[l][m] != 'R')cur_cnt++;
							}
						}
					}
					if (cur_cnt <= ans)ans = cur_cnt;
					//printf("i:%d j:%d k:%d ans:%d\n",i,j,k,ans);

				
			}
		}
		printf("#%d %d\n", tc, ans);
		ans = 9999;
	}

	
	return 0;
}
