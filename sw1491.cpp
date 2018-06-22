//1491. 원재의 벽 꾸미기

#include<stdio.h>
#include<string>
#include<stdlib.h>

using namespace std;

int test_case;
int N, A, B;
int soinsu[100002];

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		scanf("%lld %lld %lld", &N, &A, &B);
		//printf("*%d %d %d\n", N, A, B);
		long long min = 99999999999999999;
		long long cur_val = 0;
		for (long long R = 1; R <= N; R++)
		{
			for (long long C = 1; C*R <= N; C++)
			{
				if (R >= C)
				{
					cur_val = A*(R - C) + B*(N - R*C);
				}
				/*if (N%j != 0)continue;
				long long  R = (N / j);
				long long C = j;
				cur_val = A*(R - C);
				if (cur_val < 0)cur_val = cur_val*(-1);*/
				if (cur_val <= min)min = cur_val;
				//if (min < 0)printf("!@#min: %d R:%d C:%d\n", min, R, C);
			}
		}
		//for (int j = 1; j*j <= N; j++)
		//{
		//	if ((B*(N - j*j)) < 0)continue;
		//	if ((B*(N - j*j)) <= min) min = B*(N - j*j);
		//	//printf("j:%d min:%d\n", j, min);
		//}
		printf("#%d %lld\n", i + 1, min);
	}
	return 0;
}


//다른 사람 풀이 http://ppikanyang.tistory.com/entry/1491-%EC%9B%90%EC%9E%AC%EC%9D%98-%EB%B2%BD-%EA%BE%B8%EB%AF%B8%EA%B8%B0
//또 다른 사람 풀이 http://shalgorithmstd.tistory.com/68
/*
#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        long long N, A, B;
        long long min, cal;
        scanf("%d %d %d", &N, &A, &B);
        min = N*(A+B);
        
        for (int R = 1;  R<= N; R++)
        {
                for (int C = 1; C*R<=N; C++)
                {
                    if (R>=C) cal = A*(R - C) + B*(N - R*C);
                    if (min>cal) min = cal;
                }
        }
        printf("#%d %d\n", tc, min);
        //cout << "#" << tc << " " << min << endl;
    }
}
*/
