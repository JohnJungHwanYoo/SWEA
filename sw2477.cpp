//2477 차량정비소

#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

int test_case;
int N, M, k, A, B;//N:접수 창구의 개수, M:정비창구의 개수, 
					//k:방문 고객의 수, A,B: 지갑 두고 간 놈 접수/정비 창구
int k_time[1001];
int AB_check[2][1001];
int a_flag[3][11];//0행 flag,1행 남은 시간,2행 고객번호
int b_flag[3][11];//0행 flag,1행 남은 시간,2행 고객번호
int a_waiting_time[11];
int b_waiting_time[11];
int cnt=0;
bool state = false;
int max_tk;

void init(void)										//초기화 작업 해야함.
{
	max_tk = 0;
	state = false;
	cnt = 0;
	return;
}

int flag_check(int A[], int B[])
{
	for (int i = 1; i <= N; i++)
	{
		if (A[i] == 1)
		{
			return 0;
			break;
		}
	}
	for (int j = 1; j <= M; j++)
	{
		if (B[j] == 1)
		{
			return 0;
			break;
		}
	}
	return 1;
	
}

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		init();

		scanf("%d %d %d %d %d", &N, &M, &k, &A, &B);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a_waiting_time[i]);
		}
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &b_waiting_time[j]);
		}
		for (int tk = 1; tk <= k; tk++)
		{
			scanf("%d", &k_time[tk]);
			if (tk == k)max_tk = k_time[tk];
		}

		queue<int>A_waiting_Q;
		queue<int>B_waiting_Q;				//나중에 초기화?

		while (1)
		{
			//for (int i = 0; i < 3; i++)
			//{
			//	for (int j = 0; j < 11; j++)
			//	{
			//		printf("%d ", a_flag[i][j]);
			//	}
			//	printf("\n");
			//}
			//printf("\n");

			//for (int i = 0; i < 3; i++)
			//{
			//	for (int j = 0; j < 11; j++)
			//	{
			//		printf("%d ", b_flag[i][j]);
			//	}
			//	printf("\n");
			//}
			//printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

			cnt++;
			for (int i = 1; i <= k; i++)//i가 고객
			{
				if (k_time[i] == 0)
				{
					A_waiting_Q.push(i);
				}
				k_time[i] = k_time[i] - 1;
			}


			for (int i = 1; i <= N; i++)
			{
				if (a_flag[0][i] == 0 && !A_waiting_Q.empty()) // 처음 들어올 때
				{
					a_flag[0][i] = 1;
					a_flag[1][i] = a_waiting_time[i];
					AB_check[0][A_waiting_Q.front()] = i;//창구가 i
					a_flag[2][i] = A_waiting_Q.front();

					A_waiting_Q.pop();
				}
				else if (a_flag[0][i] == 1)
				{
					a_flag[1][i] = a_flag[1][i] - 1;
					if (a_flag[1][i] == 0)//시간이 다 되었을 때
					{
						a_flag[0][i] = 0;
						B_waiting_Q.push(a_flag[2][i]);
						a_flag[2][i] = 0;
						if (!A_waiting_Q.empty())
						{
							a_flag[0][i] = 1;
							a_flag[1][i] = a_waiting_time[i];
							AB_check[0][A_waiting_Q.front()] = i;//창구가 i
							a_flag[2][i] = A_waiting_Q.front();

							A_waiting_Q.pop();
						}
					}
				}
				
			}

			for (int i = 1; i <= M; i++)
			{
				if (b_flag[0][i] == 0 && !B_waiting_Q.empty()) // 정비소 처음 들어올 때
				{
					b_flag[0][i] = 1;
					b_flag[1][i] = b_waiting_time[i];
					AB_check[1][B_waiting_Q.front()] = i;//창구가 i
					b_flag[2][i] = B_waiting_Q.front();
					B_waiting_Q.pop();
				}
				else if (b_flag[0][i] == 1)
				{
					b_flag[1][i] = b_flag[1][i] - 1;
					if (b_flag[1][i] == 0)//시간이 다 되었을 때
					{
						b_flag[0][i] = 0;
						b_flag[2][i] = 0;
						if (!B_waiting_Q.empty())
						{
							b_flag[0][i] = 1;
							b_flag[1][i] = b_waiting_time[i];
							AB_check[1][B_waiting_Q.front()] = i;//창구가 i
							b_flag[2][i] = B_waiting_Q.front();

							B_waiting_Q.pop();
						}
					}
				}
			}
			if (A_waiting_Q.empty() && B_waiting_Q.empty() && flag_check(a_flag[0],b_flag[0])==1 && cnt>=max_tk)break;
		}
		int sum = 0;
		for (int kk = 1; kk <= k; kk++)
		{
			if (AB_check[0][kk] == A && AB_check[1][kk] == B)
			{
				state = true;
				sum = sum + kk;
			}
		}

		if(state == true)		printf("#%d %d\n", tc, sum);
		else printf("#%d %d\n", tc, -1);
		//int AB_check[2][1001];
		//for (int i = 0; i <2; i++)
		//{
		//	for (int j = 1; j <= k; j++)
		//	{
		//		printf("%d ", AB_check[i][j]);
		//	}
		//	printf("\n");
		//}

	}

	return 0;
}
