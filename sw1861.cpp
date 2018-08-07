//SWEA 1861. 정사각형 방

#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

int test_case, N;
int DP[1002][1002];
int room[1002][1002];
int MX;
int MN_loc = 1000006;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void init(void)
{
	MX = 0;
	MN_loc = 1000006;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			DP[i][j] = -10;
			room[i][j] = 0;
		}
	}

	return;
}

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		init();
		//printf("MN_loc:%d MX:%d\n", MN_loc, MX);
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &room[i][j]);
			}
		}

		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		printf("%d ", room[i][j]);
		//	}
		//	printf("\n");
		//}
		//printf("\n");


		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				for (int dir = 0; dir < 4; dir++)
				{
					int temp_x = i + dx[dir];
					int temp_y = j + dy[dir];
					if (temp_x <= 0 || temp_x > N || temp_y <= 0 || temp_y > N)continue;

					if (DP[temp_x][temp_y]!=-10 && room[temp_x][temp_y] == room[i][j] + 1)
					{
						DP[i][j] = DP[temp_x][temp_y] + 1;
						if (DP[i][j] >= MX)
						{
							if (DP[i][j] > MX)
							{
								MX = DP[i][j];
								MN_loc = room[i][j];
							}
							else
							{
								if (room[i][j] < MN_loc)MN_loc = room[i][j];
							}
						}
						break;
					}
					else if (room[temp_x][temp_y] == room[i][j] - 1)
					{
						DP[i][j] = DP[temp_x][temp_y] - 1;
					}
				}

				if (DP[i][j] == -10)
				{
					//if (i == 1 && j == 1) printf("*\n");
					int cnt = 1;
					queue< pair<int, int> >Q;
					Q.push(make_pair(i, j));

					while (!Q.empty())
					{
						int cur_x = Q.front().first;
						int cur_y = Q.front().second;
						Q.pop();

						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur_x + dx[dir];
							int ny = cur_y + dy[dir];
							if (nx <= 0 || nx > N || ny <= 0 || ny > N)continue;
							if (room[nx][ny] == room[cur_x][cur_y] + 1)
							{
								Q.push(make_pair(nx, ny));
								cnt++;
								break;
							}
						}
					}
					DP[i][j] = cnt;
					if (DP[i][j] >= MX)
					{
						if (DP[i][j] > MX)
						{
							MX = DP[i][j];
							MN_loc = room[i][j];
						}
						else
						{
							if (room[i][j] < MN_loc)MN_loc = room[i][j];
						}
					}
					//printf("i:%d j:%d\n", i, j);
					//printf("MX:%d MN_loc:%d\n", MX, MN_loc);
				}
				


			}
		}
		printf("#%d %d %d\n", tc, MN_loc, MX);

	}

	return 0;
}


/*
#include <cstdio>
int TC, n, n2, minv, minc, ip, cost[40001], x, y, w, i, j, k, t;
short p[40001][2];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int main()
{
    scanf("%d", &TC);
    for (t = 1; t <= TC; ++t)
    {
        scanf("%d", &n);
        n2 = n * n;
        for (i = 1; i <= n2; ++i)
            cost[i] = 1;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                scanf("%d", &ip);
                p[ip][0] = i; p[ip][1] = j;
            }
        }
        for (i = n2; i >= 2; --i) {
            x = p[i][0];
            y = p[i][1];
            for (k = 0; k < 4; k++) {
                if (x + dx[k] == p[i - 1][0] && y + dy[k] == p[i - 1][1]) {
                    cost[i - 1] += cost[i];
                    break;
                }
            }
        }
        minc = cost[1]; minv = 1;
        for (i = 2; i <= n2; i++)
        {
            if (cost[i] > minc) {
                minv = i;
                minc = cost[i];
            }
        }
        printf("#%d %d %d\n", t, minv, minc);
    }
    return 0;
}
*/
