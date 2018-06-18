//1285 아름이의 돌 던지기
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int test_case;

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int num = 0;
		int arr[100002] = {};
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			int cur;
			scanf("%d", &cur);
			arr[abs(cur)]++;
			//printf("%d\n", abs(cur));
		}
		int cnt = 0;
		while (1)
		{
			if(arr[cnt] != 0)
			{
				printf("#%d %d %d\n", i + 1, cnt, arr[cnt]);
				break;
			}
				cnt++;
		}
	}
	return 0;
}
