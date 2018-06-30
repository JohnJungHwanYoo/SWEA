//  1226. [S/W 문제해결 기본] 7일차 - 미로1 D4

#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

int test_case;
char maze[17][17];
int isVisited[17][17];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> Q;

void init(void)
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			isVisited[i][j] = 0;
		}
	}
	while (!Q.empty())
	{
		Q.pop();
	}
	return;
}


int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		init();
		scanf("%d", &test_case);
		for (int j = 0; j < 16; j++)
		{
				scanf("%s", &maze[j]);
				//if (maze[j][k] == '1')isVisited[j][k] = 1;
		}
		int cur_x = 1;
		int cur_y = 1;
		Q.push({ cur_x,cur_y });
		isVisited[cur_x][cur_y] = 1;

		while (!Q.empty())
		{
			cur_x = Q.front().first;
			cur_y = Q.front().second;
			if (maze[cur_x][cur_y] == '3')break;
			Q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int new_x = cur_x + dx[dir];
				int new_y = cur_y + dy[dir];

				if (new_x < 0 || new_y < 0 || new_x >= 16 || new_y >= 16)continue;
				if (isVisited[new_x][new_y] != 1 && maze[new_x][new_y]!='1')
				{
					Q.push({ new_x,new_y });
					isVisited[new_x][new_y] = 1;
					//printf("new_x:%d new_y:%d\n", new_x, new_y);
				}
			}
		}
		if (maze[cur_x][cur_y] == '3')
			printf("#%d %d\n", test_case, 1);
		else
			printf("#%d %d\n", test_case, 0);
	}
	return 0;
}
