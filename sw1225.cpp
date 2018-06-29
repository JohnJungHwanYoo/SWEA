// 1225. [S/W 문제해결 기본] 7일차 - 암호생성기 D3

#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

int test_case;
queue<int>Q;


int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		scanf("%d,", &test_case);

		int cur_num = 0;
		for (int j = 0; j < 8; j++)
		{
			scanf("%d", &cur_num);
			Q.push(cur_num);
		}
		while (Q.back() != 0)
		{
			for (int k = 1; k <= 5; k++)
			{
				cur_num = Q.front();
				Q.pop();
				if (cur_num - k <= 0)
				{
					//printf("**push num:%d\n", cur_num - k);
					//printf("cur_num:%d k:%d\n", cur_num, k);
					Q.push(0);
					break;
				}
				else
				{
					Q.push(cur_num - k);
					//printf("cur_num:%d k:%d\n", cur_num, k);

					//printf("**push num:%d\n", cur_num - k);
				}
			}
			
		}
		printf("#%d ", i + 1);
		for (int l = 0; l < 8; l++)
		{
			cur_num = Q.front();
			printf("%d ", cur_num);
			Q.pop();
		}
		printf("\n");
		/*printf("size?: %d\n", Q.size());*/
	}
	return 0;
}
