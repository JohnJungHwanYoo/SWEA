//4466. 최대 성적표 만들기

#include<stdio.h>
#include<algorithm>
#include<functional>

using namespace std;

int test_case;

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int N, K;
		scanf("%d %d", &N, &K);
		int arr[102] = {};
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[j]);
		}
		sort(arr, arr + N, greater<int>());
		int sum = 0;
		for (int k = 0; k < K; k++)
		{
			sum = sum + arr[k];
		}
		printf("#%d %d\n", i + 1, sum);
	}
	return 0;
}
