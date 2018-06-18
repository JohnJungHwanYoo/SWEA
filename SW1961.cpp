//1961. 숫자 배열 회전
//N*N행렬
//90, 180 ,270 도 회전
// 3<=N<=7


#include<stdio.h>

int test_case;
int N;


int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int matrix[8][8] = {};
		int mod_matrix90[8][8] = {};
		int mod_matrix180[8][8] = {};
		int mod_matrix270[8][8] = {};

		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				scanf("%d", &matrix[j][k]);
			}
		}
		//90도 회전 2차원 배열
		int shift = N - 1;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				mod_matrix90[k][shift] = matrix[j][k];
					//matrix[(N - 1) - shift + j][shift - k];
			}
//			printf("shift: %d\n", shift);
			shift--;
		}

		//180도 회전 2차원 배열<- 90도에서 90도 돌려만듦
		shift = N - 1;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				mod_matrix180[k][shift] = mod_matrix90[j][k];
				//matrix[(N - 1) - shift + j][shift - k];
			}
	//		printf("shift: %d\n", shift);
			shift--;
		}
		//270도 회전 2차원 배열 <- 180도에서 90도 돌려만듦
		shift = N - 1;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				mod_matrix270[k][shift] = mod_matrix180[j][k];
				//matrix[(N - 1) - shift + j][shift - k];
			}
		//	printf("shift: %d\n", shift);
			shift--;
		}
		printf("#%d\n",i+1);
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				printf("%d", mod_matrix90[j][k]);
			}
			printf(" ");
			for (int k = 0; k < N; k++)
			{
				printf("%d", mod_matrix180[j][k]);
			}
			printf(" ");
			for (int k = 0; k < N; k++)
			{
				printf("%d", mod_matrix270[j][k]);
			}
			printf("\n");
		}
	}
	return 0;
}
