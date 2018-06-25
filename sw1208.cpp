// 1208. 1일차 Flatten

#include<stdio.h>

int height[102];

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		int dump_num = 0;
		scanf("%d", &dump_num);
		int cur_max = 0;
		int cur_min = 999;
		for (int i = 1; i <= 100; i++)
		{
			int input = 0;
			scanf("%d", &input);
			height[input]++;
			if (input <= cur_min)cur_min = input;
			if (input >= cur_max)cur_max = input;
		}
		//평탄화 작업
		for (int i = 0; i < dump_num; i++)
		{
			height[cur_min]--;
			height[cur_min + 1]++;
			height[cur_max]--;
			height[cur_max - 1]++;
			if (height[cur_min] == 0)
			{
				while (height[cur_min] == 0)
				{
				//	printf("*\n");

					cur_min++;
				}
			}
			if (height[cur_max] == 0)
			{
				while (height[cur_max] == 0)
				{
				//	printf("***\n");

					cur_max--;
				}
			}
			//printf("cur_max:%d, cur_min:%d\n", cur_max, cur_min);


		}
		int gap = cur_max - cur_min;
		printf("#%d %d\n", i + 1, gap);

		//초기화작업
		for (int i = 1; i <= 100; i++)
		{
			height[i] = 0;
		}
	}
	return 0;
}
