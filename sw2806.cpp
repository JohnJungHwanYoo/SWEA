//2806. N-Queen

#include<stdio.h>
#include<string>

using namespace std;

int test_case;
int N,cnt;
int col[12]; // column
int SE[22]; // south east dir
int SW[22]; // south west dir

int Recursion(int depth)
{
	if (depth == N)
	{
		cnt++;
	}
	for (int i = 0; i < N; i++)
	{
		if (col[i] == 1 || SE[i + depth] == 1 || SW[(N - 1) + depth - i] == 1)continue;
		col[i] = 1;
		SE[i + depth] = 1;
		SW[(N-1)+depth - i] = 1;
		Recursion(depth + 1);
		col[i] = 0;
		SE[i + depth] = 0;
		SW[(N - 1) + depth - i] = 0;
	}
	return 0;
}


int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d", &N);
		cnt = 0;
		Recursion(0);

		printf("#%d %d\n", i + 1, cnt);
		fill(col, col + N, 0);
		fill(SW, SW + 2 * N, 0);
		fill(SE, SE + 2 * N, 0);
		//Initializaing not completed
	}
	return 0;
}
