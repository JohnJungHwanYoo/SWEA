//1217. [S/W 문제해결 기본] 4일차 - 거듭 제곱

#include<stdio.h>

int test_case;

long long Recursion(int base, int exp)
{
	if (exp == 0) return 1;
	return base * Recursion(base, exp - 1);
}

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &test_case);
		int base = 0;
		int exp = 0;
		scanf("%d %d", &base, &exp);
		long long ans = 0;
		ans = Recursion(base, exp);

		printf("#%d %lld\n", i + 1, ans);
	}
	return 0;
}
