//1949. [모의 SW 역량테스트] 등산로 조성
 
#include<stdio.h>
#include<algorithm>
#include<queue>
 
using namespace std;
 
int test_case;  
int N, K;
int map[10][10];
int isVisited[10][10];
int highest;
bool K_used = false;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int pre_h;
int max_len;
 
void init()
{
    max_len = 0;
    highest = 0;
    K_used = false;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            isVisited[i][j] = 0;
        }
    }
    return;
}
 
int Recursion(int len, int height, int x, int y)
{
    for (int dir = 0; dir<4; dir++)
    {
        int new_x = x + dx[dir];
        int new_y = y + dy[dir];
 
        if (new_x >= N || new_x < 0 || new_y >= N || new_y < 0)continue;
        if (isVisited[new_x][new_y] == 1)continue;
 
        if (map[new_x][new_y] < height)
        {
            isVisited[new_x][new_y] = 1;
            Recursion(len + 1, map[new_x][new_y], new_x, new_y);
            isVisited[new_x][new_y] = 0;
        }
 
        else if (map[new_x][new_y] >= height && K_used == false && (map[new_x][new_y] - K) < height)
        {
            pre_h = map[new_x][new_y];
            map[new_x][new_y] = height - 1;
            isVisited[new_x][new_y] = 1;
            K_used = true;
            Recursion(len + 1, height - 1, new_x, new_y);
            map[new_x][new_y] = pre_h;
            isVisited[new_x][new_y] = 0;
            K_used = false;
        }
         
    }
    if (len >= max_len)max_len = len;
    return 0;
}
 
 
int main(void)
{
    scanf("%d", &test_case);
    for (int tc = 1; tc <= test_case; tc++)
    {
        init();
        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &map[i][j]);
                if (map[i][j] >= highest)highest = map[i][j];
            }
        }
        // map 입력 끝
 
        // 등산로 계산 시작
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] == highest)
                {
                    isVisited[i][j] = 1;
                    Recursion(1, map[i][j], i, j);
                    isVisited[i][j] = 0;
                }
            }
        }
 
        printf("#%d %d\n", tc, max_len);
 
    }
    return 0;
}
