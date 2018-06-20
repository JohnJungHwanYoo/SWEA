// 2817. 부분 수열의 합

#include<stdio.h>

int test_case;

int sum, cnt;
int N, K;
int arr[22];

int Recursion(int K,int lastidx)
{
	if (sum == K)
	{
		cnt++;
		return 0;
	}
	for (int i = lastidx + 1; i < N; i++)
	{
		sum = sum + arr[i];
		Recursion(K, i);
		sum = sum - arr[i];
	}

}



int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d %d", &N, &K);
		sum = 0;
		cnt = 0;
		arr[22] = {};
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[j]);
		}

		Recursion(K,-1);
		printf("#%d %d\n", i + 1, cnt);
	}
	return 0;
}


/* 다른 사람 풀이

합을 체크하는 배열을 만들어서 큰 수부터 채워 넣는 방식
(작은 수부터 채워 넣으면 중복 합이 될까봐 그런 것 같음)
조금 더 살펴봐야하는 풀이.
직접 해볼 것.

#include<stdio.h>
int T;
int N, K;
int val[21];
int ch_arr[1001];

int main() {
	int i, j, t;

	scanf("%d", &T);
	for (t = 1; t <= T; t++) 
	{
		scanf("%d %d", &N, &K);

		for (i = 0; i <= K; i++) ch_arr[i] = 0;

		for (i = 0; i < N; i++) 
		{
			scanf("%d", &val[i]);
			for (j = K; j >= 0; j--) 
			{
				if (j + val[i] > K) continue;

				if (ch_arr[j] != 0) 
				{
					ch_arr[j + val[i]] += ch_arr[j];
				}
				//for (int k = 0; k <= N; k++)
				//{
				//	printf("%d ", ch_arr[k]);
				//}
				printf("\n");
			}
			ch_arr[val[i]] += 1;
		}
		printf("#%d %d\n", t, ch_arr[K]);
	}
	return 0;
}

*/
