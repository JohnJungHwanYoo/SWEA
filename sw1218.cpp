//1218.[S / W 문제해결 기본] 4일차 - 괄호 짝짓기 D4


#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

int num;
char arr[10000];
int isVisited[10000];

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &num);
		scanf("%s", arr);

		stack<char> S;

		S.push(arr[0]);
		isVisited[0] = 1;
		int cnt = 1;
		for(cnt = 1;cnt<num;cnt++)
		{
			if(arr[cnt]=='(' || arr[cnt] == '[' || arr[cnt] == '{' || arr[cnt] == '<')
			{
				S.push(arr[cnt]);
				isVisited[cnt] = 1;
				//printf("**\n");
				continue;
			}
			else 
			{
				if (S.top() == '(' && arr[cnt] == ')')
				{
					S.pop();
					isVisited[cnt] = 1;
				}
				else if (S.top() == '[' && arr[cnt] == ']')
				{
					S.pop();
					isVisited[cnt] = 1;
				}
				else if (S.top() == '{' && arr[cnt] == '}')
				{
					S.pop();
					isVisited[cnt] = 1;
				}
				else if (S.top() == '<' && arr[cnt] == '>')
				{
					S.pop();
					isVisited[cnt] = 1;
				}
				else
				{
					printf("#%d %d\n", i + 1, 0);
					break;
				}
			}
		
		}
		if (S.empty() == true)
		{
			printf("#%d %d\n", i + 1, 1);
		}
	/*	for (int i = 0; i < num; i++)
		{
			printf("%d", isVisited[i]);
		}
		printf("\n");*/
		fill(arr, arr + num, 0);
		fill(isVisited, isVisited + num, 0);
	}
	return 0;
}
