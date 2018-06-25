//1211. [S/W 문제해결 기본] 2일차 - Ladder2 D4

 
#include<stdio.h>
#include<algorithm>
#include<functional>
 
using namespace std;
 
int board[102][102];
 
 
int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        int start_point[102] = {};
        int cnt[102] = {};
        int test_case = 0;
        scanf("%d", &test_case);
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                scanf("%d", &board[i][j]);
            }
        }
        int start_num = 0;
        for (int i = 0; i < 100; i++)
        {
            if (board[0][i] == 1)
            {
                start_point[start_num] = i;
                start_num++;
 
            }
        }
 
        for (int i = 0; i < start_num; i++)
        {
            int state = 0;
            int row = 0;
            int col = start_point[i];
            int cur_cnt = 0;
            while (row != 100)
            {
                if (board[row][col - 1] == 1)
                {
                    //printf("@ row:%d, col:%d\n",row,col);
                    state = -1;
                    while (board[row][col - 1] != 0)
                    {
                        col = col + state;
                        cur_cnt++;
                    }
                    state = 0;
                    row++;
                }
                else if (board[row][col + 1] == 1)
                {
                    //printf("# row:%d, col:%d\n", row, col);
                    state = 1;
                    while (board[row][col + 1] != 0)
                    {
                        col = col + state;
                        cur_cnt++;
 
                    }
                    row++;
                    state = 0;
                }
                else
                {
                    //printf("$ row:%d, col:%d\n", row, col);
                    row++;
                    cur_cnt++;
 
                }
 
 
            }
            cnt[i] = cur_cnt;
        }
/*
        for (int i = 0; i < start_num; i++)
        {
            printf("%d ", cnt[i]);
        }
        printf("\n");
*/
        int path_min = 9999;
        int path_min_index = 9999;
        for (int i = 0; i < start_num; i++)
        {
            if (cnt[i] < path_min)
            {
                path_min = cnt[i];
                path_min_index = start_point[i];
            }
        }
 
        printf("#%d %d\n", test_case,path_min_index);
    }
    return 0;
}
