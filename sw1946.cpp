//1946 간단한 압축풀기

#include<stdio.h>

int test_case;

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int N = 0;
		char word[11] = {};
		int num[11] = {};

		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%s", &word[j]);
			scanf("%d", &num[j]);
		//	printf("j: %d\n", j);
		}
		printf("#%d\n", i + 1);

		int ten_check = 10;
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < num[j]; k++)
			{
				printf("%c", word[j]);
				cnt++;
				if ((cnt % 10) == 0)printf("\n");
			}
		}
		printf("\n");
	}




	return 0;
}
