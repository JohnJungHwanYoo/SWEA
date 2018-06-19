//3233. 정삼각형 분할 놀이

#include<stdio.h>

int test_case;

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		long long A, B;
		scanf("%lld %lld", &A, &B);
		long long quot = A / B;
		printf("#%d %lld\n", i + 1, quot*quot);

	}
	return 0;
}
 
