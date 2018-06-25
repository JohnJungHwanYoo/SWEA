//1206. 1일차 view

#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

//int test_case;
int height[1002];

int main(void)
{
	//scanf("%d", &test_case);
	for (int i = 1; i <= 10; i++)
	{
		int input = 0;
		scanf("%d", &input);
		for (int j = 0; j < input; j++)
		{
			scanf("%d", &height[j]);
		}
		int cnt = 0;
		for (int k = 2; k < input-2; k++)
		{
			bool state = true;
			int cur_max = 0;
			for (int l = -2; l <= 2; l++)
			{
				if (l == 0)continue;					//자기 자신과 비교 제외
				if (height[k] <= height[k + l])
				{
					state = false;
					break;
				}
				if (height[k+l]>=cur_max)cur_max = height[k+l];
				p//rintf("cur_max: %d\n", cur_max);
			}
			if(state)cnt = cnt + (height[k]- cur_max);
			//printf("k: %d, cnt: %d\n", k, cnt);
		}
		fill(height, height + input, 0);
		printf("#%d %d\n", i, cnt);
	}
	return 0;
}
