//2117. [모의 SW 역량테스트] 홈 방범 서비스

#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

int test_case;
int N, M;//N: 맵 크기, M:하나의 집이 지불할 수 있는 비용
int map[22][22];
//int isVisited[22][22];
int max_cnt;
int K_arr[22];

void init(void)
{
	max_cnt = 0;

	return;
}

int main(void)
{
	for (int i = 1; i <= 21; i++)
	{
		K_arr[i] = i * i + (i - 1)*(i - 1);
		//printf("%d ", K_arr[i]);
	}


	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		init();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		int K_end = 0;
		if ((N % 2) == 0) K_end = N + 1;
		else K_end = N;

		//Solve
		int K = 0;
		for (K = 1; K <= K_end; K++)
		{
			for (int x = 0; x < N; x++)
			{
				for (int y = 0; y < N; y++)
				{
					//printf("change\n");
					//한 경우에 대해서 세기 시작
					int cur_cnt = 0;
					//상단 확인
					for (int i = -(K - 1); i < 0; i++)
					{
						for (int j =-(K-1)-i; j <= (K-1)+i; j++)
						{
							//printf("*\n");
							if (x + i < 0 || x + i >= N || y + j < 0 || y + j >= N)continue;
							if (map[x + i][y + j] == 0)continue;
							else if (map[x + i][y + j] == 1)cur_cnt++;
						}
					}
					//하단 확인
					for (int i = (K - 1); i > 0; i--)
					{
						for (int j = (K - 1) - i; j >= -(K - 1) + i; j--)
						{
							//printf("**\n");
							if (x + i < 0 || x + i >= N || y + j < 0 || y + j >= N)continue;
							if (map[x + i][y + j] == 0)continue;
							else if (map[x + i][y + j] == 1)cur_cnt++;
						}
					}
					//중간 라인 확인
					for (int j = (K - 1); j >= -(K - 1); j--)
					{
						//printf("***\n");
						if (y + j < 0 || y + j >= N)continue;
						if (map[x][y + j] == 0)continue;
						else if (map[x][y + j] == 1)cur_cnt++;
					}

					//if (cur_cnt >= max_cnt)max_cnt = cur_cnt;
					if (M*cur_cnt - K_arr[K] < 0)continue;
					if (cur_cnt >= max_cnt)
					{
						max_cnt = cur_cnt;
						/*printf("맥스인 경우\n");
						printf("K:%d x:%d y:%d\n", K, x, y);
						printf("K_arr[K]:%d cur_cnt\n", K_arr[K], cur_cnt);*/
					}
					//printf("cur_cnt:%d\n", cur_cnt);
				}
			}
		}
		printf("#%d %d\n", tc, max_cnt);
	}
	return 0;
}


//시간 초과 풀이
/*


// 2117. [모의 SW 역량테스트] 홈 방범 서비스

#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

int test_case;
int N, M; // 도시 크기 N, 하나의 집이 지불할 수 있는 비용 M
int map[22][22];
int isVisited[22][22];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int K_arr[22];
int max_cnt;
int max_fee;
int ans;

queue<pair<int, int>>Q;

void isVisited_init()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			isVisited[i][j] = 0;
		}
	}
	return;
}

void init(void)
{
	ans = 0;
	max_fee = 0;
	isVisited_init();
	int len = Q.size();
	for (int i = 0; i < len; i++)
	{
		Q.pop();
	}
	max_cnt = 0;


	return;
}


int main(void)
{
	for (int i = 1; i <= 21; i++)
	{
		K_arr[i] = i * i + (i - 1)*(i - 1);
	}

	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}


		//Solving starts.
		int K_end = 0;
		if ((N % 2) == 0)K_end = N + 1;
		else K_end = N;
		
		int cur_cnt = 0;
		max_cnt = 0;
		int K = 0;

		for (K = 1; K <= K_end; K++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cur_cnt = 0;
					if (map[i][j] == 1)cur_cnt=1;
					isVisited_init();
					Q.push({ i,j });
					isVisited[i][j] = 1;
					int cur_N = 1;
					while (!Q.empty())
					{
						int cur_x = Q.front().first;
						int cur_y = Q.front().second;
						Q.pop();
						if (cur_N < K+1)
						{
							for (int dir = 0; dir < 4; dir++)
							{
								int new_x = cur_x + dx[dir];
								int new_y = cur_y + dy[dir];

								if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N)continue;
								if (isVisited[new_x][new_y]!=0)continue;

								Q.push({ new_x,new_y });
								isVisited[new_x][new_y] = isVisited[cur_x][cur_y]+1;
								cur_N = isVisited[new_x][new_y];

								if (map[new_x][new_y] == 1 && isVisited[new_x][new_y]<=K)
								{
									cur_cnt++;
									int cur_fee = 0;
									if (cur_cnt * M - K_arr[K] < 0)continue;
									if (cur_cnt >= max_cnt)max_cnt = cur_cnt;
									
								}
							}
						}			
					}			
				}
			}
		}
		printf("#%d %d\n", tc, max_cnt);
	}
	return 0;
}
*/
