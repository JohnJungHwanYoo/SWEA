//1219.[S / W 문제해결 기본] 4일차 - 길찾기 D4

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

int num;
int test_case;
int size1[101];
int size2[101];
int isVisited[101];
stack<int> S;

void init(void)
{
	num = 0;
	fill(size1, size1 + 100, 0);
	fill(size2, size2 + 100, 0);
	fill(isVisited, isVisited + 100, 0);
	int len = S.size();
	for (int i = 0; i < len; i++)S.pop();
	return;
}

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		init();
		int cur_index = 0;
		scanf("%d %d", &test_case, &num);
		for (int j = 1; j <= num; j++)
		{
			if (j % 2 == 1)
			{
				scanf("%d", &cur_index);
				scanf("%d", &size1[cur_index]);
			}
			else
			{
				scanf("%d", &cur_index);
				scanf("%d", &size2[cur_index]);
			}
		}
		//for (int i = 0; i <= 100; i++)
		//{
		//	printf("%d ", size1[i]);
		//}
		//printf("\n");
		//for (int i = 0; i <= 100; i++)
		//{
		//	printf("%d ", size2[i]);
		//}
		//printf("\n");

		//printf("size:%d\n", S.size());

		S.push(size1[0]);
		isVisited[0] = 1;


		while (S.top() != 99)
		{
			if (size1[S.top()] != 0 && isVisited[size1[S.top()]] == 0)
			{
				//printf("*\n");
				isVisited[size1[S.top()]] = 1;
				S.push(size1[S.top()]);

			}
			else if (size2[S.top()] != 0 && isVisited[size2[S.top()]] == 0)
			{
				isVisited[size2[S.top()]] = 1;

				S.push(size2[S.top()]);

			}
			else S.pop();
			//printf("S.size:%d\n", S.size());
			if (S.size() == 0)
			{
				S.push(100);
				break;
			}
		}
		if (S.top() == 99)printf("#%d %d\n", i + 1, 1);
		else if (S.top() == 100)printf("#%d %d\n", i + 1, 0);
	}
	return 0;
}
