//1284. 수도 요금 경쟁
#include<stdio.h>

int test_case;	

int B_company_calc(int Q, int R, int S, int W)
{
	if (W <= R) return Q;
	else if (W > R)
	{
		int tot = Q + S*(W - R);
		return tot;
	}
}

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int P, Q, R, S, W;
		scanf("%d %d %d %d %d", &P, &Q, &R, &S, &W);
		int A_company = P*W;
		int B_company = B_company_calc(Q, R, S, W);
		if (A_company >= B_company)
		{
			printf("#%d %d\n", i + 1, B_company);
		}
		else printf("#%d %d\n", i + 1, A_company);
	
	}
	return 0;
}
