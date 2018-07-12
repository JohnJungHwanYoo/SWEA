// 2819. 격자판의 숫자 이어 붙이기 D4

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int test_case, ans;
int board[5][5];
int num_check[10'000'000];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void init(void)
{
/*	for (int i = 0; i < 10000000; i++)
	{
		num_check[i] = 0;
	}*/
	ans = 0;
	return;
}

void Recursion(int x, int y, int depth,int cur_result,int tc)
{
	if (depth == 6)
	{
		cur_result = cur_result*10 + board[x][y];
		if (num_check[cur_result] != tc)
		{
			num_check[cur_result] = tc;
			ans++;
		}

		//printf("board:%d cur_result:%d\n", board[x][y], cur_result);

		return;
	}
	cur_result = cur_result * 10 + board[x][y];
	for (int dir = 0; dir < 4; dir++)
	{
		int new_x = x + dx[dir];
		int new_y = y + dy[dir];
		if (new_x >= 4 || new_y >= 4 || new_x < 0 || new_y < 0)continue;
		Recursion(new_x, new_y, depth + 1,cur_result, tc);

	}
	return;

}

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		init();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				scanf("%d", &board[i][j]);
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Recursion(i, j, 0,0,tc);
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;

}

/*
메모리를 적게 쓴 풀이. vector라서 그런 듯.

#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
 
using namespace std;
 
int arr[4][4];
vector<int> result;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
 
void solve(int row, int col, int cnt, int val)
{
    if (cnt == 7)
    {
        result.push_back(val);
        return;
    }
 
    for (int i = 0; i < 4; i++)
    {
        int nextY = row + dy[i];
        int nextX = col + dx[i];
        if (nextY >= 0 && nextY < 4 && nextX >= 0 && nextX < 4)
        {
            solve(nextY, nextX, cnt + 1, val * 10 + arr[nextY][nextX]);
        }
    }
}
 
int main()
{
    int T;
    scanf("%d", &T);
 
    for (int test = 1; test <= T; test++)
    {
        result.clear();
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
 
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                solve(i, j, 1, arr[i][j]);
            }
        }
 
        sort(result.begin(), result.end());
 
        int pivot = result[0];
        int res = 1;
        for (int i = 1; i < result.size(); i++)
        {
            if (result[i] != pivot)
            {
                pivot = result[i];
                res++;
            }
        }
        printf("#%d %d\n", test, res);
 
    }
}

*/
