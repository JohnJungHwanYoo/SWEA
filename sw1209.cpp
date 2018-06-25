// 1209. [S/W 문제해결 기본] 2일차 - Sum D3

#include<stdio.h>
#include<algorithm>

using namespace std;

int col[102];
int row[102];
int slider;
int reverse_slider;
int board[102][102];

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		int col[102] = {};
		int row[102] = {};
		int slider = 0;
		int reverse_slider = 0;
		int test_case = 0;
		scanf("%d", &test_case);
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				scanf("%d", &board[i][j]);
			}
		}
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				row[i] = row[i] + board[i][j];
				col[i] = col[i] + board[j][i];
			}
		}
		sort(row, row + 100);
		sort(col, col + 100);

		int row_max = row[99];
		int col_max = col[99];

		int r_c_max = max(row_max, col_max);

		for (int i = 0; i < 100; i++)
		{
			slider = slider + board[i][i];
			reverse_slider = reverse_slider + board[i][99 - i];
		}

		int slider_max = max(slider, reverse_slider);

		int ans = max(r_c_max,slider_max);
		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}
