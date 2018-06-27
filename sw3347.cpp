//3347. 올림픽 종목 투표

#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;

int test_case;
int N, M;
int A[1002];
int B[1002];
int vote_A[1002];

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d %d", &N, &M);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &A[j]);
		}
		for (int k = 0; k < M; k++)
		{
			scanf("%d", &B[k]);
		}

		for (int k = 0; k < M; k++)
		{
			for (int j = 0; j < N; j++)
			{
				if (B[k] < A[j])continue;
				else if (B[k] >= A[j])
				{
					vote_A[j]++;
					break;
				}
			}
		}
		int cur_max = 0;
		int max_index = 0;
		for (int j = 0; j < N; j++)
		{
			if (vote_A[j] > cur_max)
			{
				cur_max = vote_A[j];
				max_index = j;
			}
		}

		printf("#%d %d\n", i + 1, max_index+1);
		fill(A, A + N,0);
		fill(B, B + M, 0);
		fill(vote_A, vote_A + N, 0);
	}
	return 0;
}
