// 1953. [모의 SW 역량테스트] 탈주범 검거
 
#include<stdio.h>
#include<algorithm>
#include<queue>
 
using namespace std;
 
int test_case;
int N, M, R, C, L;//세로, 가로, 맨홀위치,맨홀위치, 시간
int map[51][51][4];
int isVisited[51][51];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
 
int cases[8][4] = { { 0,0,0,0 },{ 1,1,1,1 },{ 0,1,0,1 },{ 1,0,1,0 },{ 0,0,1,1 },{ 0,1,1,0 },{ 1,1,0,0 },{ 1,0,0,1 } };
//좌하우상
 
queue<pair<int, int>>Q;
 
void init(void)
{
    int queue_len = Q.size();
    for (int i = 0; i < queue_len; i++)
    {
        Q.pop();
    }
 
    for (int j = 0; j < 50; j++)
    {
        for (int k = 0; k < 50; k++)
        {
            isVisited[j][k] = 0;
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
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int cur_case = 0;
                scanf("%d", &cur_case);
                for (int k = 0; k < 4; k++)
                {
                    map[i][j][k] = cases[cur_case][k];
                }
            }
        }
        Q.push({ R,C });
 
        int level = 1;
        isVisited[R][C] = level;
        int cur_L = 1;
        int max_level = 0;
        while (!Q.empty())//cur_L != L
        {
 
            int cur_x = Q.front().first;
            int cur_y = Q.front().second;
            Q.pop();
            //printf("empty?:%d cur_L:%d\n", Q.empty(), cur_L);
            //printf("cur_L:%d cur_x:%d cur_y:%d empty?:%d\n", cur_L, cur_x, cur_y, Q.empty());
            //if(!Q.empty())printf("%d %d\n", Q.front().first, Q.front().second);
            //cur_L++;
            for (int dir = 0; dir < 4; dir++)
            {
                int new_x = cur_x + dx[dir];
                int new_y = cur_y + dy[dir];
 
                if (new_x >= N || new_x < 0 || new_y >= M || new_y < 0)continue;
                if (isVisited[new_x][new_y] != 0)continue;
 
                if (map[cur_x][cur_y][dir] && map[new_x][new_y][(dir + 2) % 4])
                {
                    isVisited[new_x][new_y] = isVisited[cur_x][cur_y]+1;
                    cur_L = isVisited[new_x][new_y];
                    Q.push({ new_x,new_y });
                    //printf("dir:%d new_x:%d new_y:%d\n",dir,new_x,new_y);
 
                }
            }
            if (cur_L > L)break;
 
        }
        int sum = 0;
        //printf("\n");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                //printf("%d ", isVisited[i][j]);
                if (isVisited[i][j] <= L && isVisited[i][j] > 0)
                {
                    sum = sum + 1;
                }
            }
            //printf("\n");
        }
 
        printf("#%d %d\n", tc, sum);
    }
    return 0;
}

//다른 사람 풀이
/*

#include <iostream>
#include <queue>
using namespace std;
 
int d[50][50];
int dist[50][50];
int result;
int N, M, R, C, L;
bool check[50][50];
void go(int L, int i, int j);
 
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &d[i][j]);
            }
        }
        result = 0;
        go(L, R, C);
        printf("#%d %d\n", t, result);
 
        if (t != T) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    check[i][j] = false;
                    dist[i][j] = 0;
                }
            }
        }
    }
    return 0;
}
 
bool checkUp(int i, int j) {
    if ((i > 0 && !check[i - 1][j]) && (d[i - 1][j] == 1 || d[i - 1][j] == 2 || d[i - 1][j] == 5 || d[i - 1][j] == 6)) {
        dist[i - 1][j] = dist[i][j] + 1;
        return true;
    }
    return false;
}
 
bool checkDown(int i, int j) {
    if ((i < N-1 && !check[i + 1][j]) && (d[i + 1][j] == 1 || d[i + 1][j] == 2 || d[i + 1][j] == 4 || d[i + 1][j] == 7)) {
        dist[i + 1][j] = dist[i][j] + 1;
        return true;
    }
    else return false;
}
 
bool checkLeft(int i, int j) {
    if ((j > 0 && !check[i][j - 1]) && (d[i][j - 1] == 1 || d[i][j - 1] == 3 || d[i][j - 1] == 4 || d[i][j - 1] == 5)) {
        dist[i][j - 1] = dist[i][j] + 1;
        return true;
    }
    else return false;
}
 
bool checkRight(int i, int j) {
    if ((j < M-1 && !check[i][j + 1]) && (d[i][j + 1] == 1 || d[i][j + 1] == 3 || d[i][j + 1] == 6 || d[i][j + 1] == 7)) {
        dist[i][j + 1] = dist[i][j] + 1;
        return true;
    }
    else return false;
}
 
void go(int Lvar, int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    dist[i][j] = 1;
    while (!q.empty()) {
        int ni = q.front().first; int nj = q.front().second;
        q.pop();
        if (!check[ni][nj] && dist[ni][nj] <= Lvar) {
            if (d[ni][nj] == 1) {
                if (checkUp(ni, nj)) q.push(make_pair(ni - 1, nj));
                if (checkDown(ni, nj)) q.push(make_pair(ni + 1, nj));
                if (checkLeft(ni, nj)) q.push(make_pair(ni, nj - 1));
                if (checkRight(ni, nj)) q.push(make_pair(ni, nj + 1));
            }
            else if (d[ni][nj] == 2) {
                if (checkUp(ni, nj)) q.push(make_pair(ni - 1, nj));
                if (checkDown(ni, nj)) q.push(make_pair(ni + 1, nj));
            }
            else if (d[ni][nj] == 3) {
                if (checkLeft(ni, nj)) q.push(make_pair(ni, nj - 1));
                if (checkRight(ni, nj)) q.push(make_pair(ni, nj + 1));
            }
            else if (d[ni][nj] == 4) {
                if (checkUp(ni, nj)) q.push(make_pair(ni - 1, nj));
                if (checkRight(ni, nj)) q.push(make_pair(ni, nj + 1));
            }
            else if (d[ni][nj] == 5) {
                if (checkDown(ni, nj)) q.push(make_pair(ni + 1, nj));
                if (checkRight(ni, nj)) q.push(make_pair(ni, nj + 1));
            }
            else if (d[ni][nj] == 6) {
                if (checkLeft(ni, nj)) q.push(make_pair(ni, nj - 1));
                if (checkDown(ni, nj)) q.push(make_pair(ni + 1, nj));
            }
            else if (d[ni][nj] == 7) {
                if (checkUp(ni, nj)) q.push(make_pair(ni - 1, nj));
                if (checkLeft(ni, nj)) q.push(make_pair(ni, nj - 1));
            }
 
            result++;
            check[ni][nj] = true;
        }
    }
}
*/
