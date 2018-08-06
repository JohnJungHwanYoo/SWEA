// SWEA 1494. 사랑의 카운슬러
// baaaaaaaaaaaaakingdog 님의 풀이 따라 풀어본 코드

#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PAIR;
#define X first
#define Y second
int main(void)
{
	int T;
	scanf("%d", &T);
	PAIR point[30];
	for(int tc = 1;tc<=T;tc++)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%lld %lld", &point[i].X, &point[i].Y);
		LL MN = 0x7fffffffffffffffLL;
		vector<int> brute(N);
		fill(brute.begin() + N / 2, brute.end(), 1);
		do {
			PAIR val = { 0LL,0LL };
			for (int i = 0; i < N; i++)
			{
				if (brute[i]) 
				{
					val.X += point[i].X;
					val.Y += point[i].Y;
				}
				else
				{
					val.X -= point[i].X;
					val.Y -= point[i].Y;
				}
			}
			MN = min(MN, val.X*val.X + val.Y*val.Y);
		} while (next_permutation(brute.begin(), brute.end()));
		printf("#%d %lld\n", tc, MN);
		//printf("%.6f\n", sqrt((double)MN));
	}
	return 0;
}


/* <원래 내 풀이>
#include<stdio.h>
#include<stdlib.h>

int test_case,N;
int input_vectors[2][22];
int isVisted[22];
long long minn=99999999999;

void init(void)
{
	minn = 99999999999;
	for (int i = 0; i < 22; i++)
	{
		isVisted[i] = 0;
	}
	return;
}


void dfs(int depth,int lastidx)
{
	if (depth == N / 2)
	{
		long long cur_ans_x = 0;
		long long cur_ans_y = 0;
		long long goals[2] = {};
		long long starts[2] = {};
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (isVisted[i])
				{
					goals[j] = goals[j] + input_vectors[j][i];
				}
				else
				{
					starts[j] = starts[j] + input_vectors[j][i];
				}
			}
		}
		cur_ans_x = goals[0] - starts[0];
		cur_ans_y = goals[1] - starts[1];
		//printf("start[0]:%lld start[1]:%lld goal[0]:%lld goal[1]:%lld cur_ans_x:%lld cur_ans_y:%lld\n", starts[0], starts[1], goals[0], goals[1], cur_ans_x, cur_ans_y);
		long long cur_ans = cur_ans_x * cur_ans_x + cur_ans_y * cur_ans_y;
		if (cur_ans < minn)minn = cur_ans;
		return;
	}

	for (int i = lastidx+1; i < N; i++)
	{
		if (!isVisted[i])
		{
			isVisted[i] = 1;
			dfs(depth + 1,i);
			isVisted[i] = 0;
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
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				scanf("%d", &input_vectors[j][i]);
			}
		}

		dfs(0,-1);

		printf("#%d %lld\n", tc, minn);


	}

	return 0;
}
*/
/*<속도가 획기적으로 빨랐던 풀이>
#include <iostream>
using namespace std;
 
long int n, ans;
long int x[20];
long int y[20];
long int cntP, cntM;
 
void ansF(long int start, long int sumX, long int sumY) {
    if(cntP == n/2 && cntM == n/2)  {
        long int temp;
        temp = sumX * sumX + sumY * sumY;
        if(ans > temp)   ans = temp;
        return ;
    }
 
    if(cntP < n/2)   {
        cntP++;
        ansF(start + 1, sumX + x[start + 1], sumY + y[start + 1]);
        cntP--;
    }
    if(cntM < n/2)   {
        cntM++;
        ansF(start + 1, sumX - x[start + 1], sumY - y[start + 1]);
        cntM--;
    }
    return ;
}
 
 
int main()  {
    long int tc;
    cin >> tc;
 
    for(long int i = 1; i <= tc; i++)    {
        cin >> n;
        for(long int j = 0; j < n; j++)  cin >> x[j] >> y[j];
 
        cntP = 1;
        cntM = 0;
        ans = 99999999999;
 
        ansF(0, x[0], y[0]);
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}
*/
