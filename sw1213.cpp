//1213. [S/W 문제해결 기본] 3일차 - String 

#include<stdio.h>
#include<string.h>
#include<string>

using namespace std;

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		int test_case = 0;
		scanf("%d", &test_case);
		char check[11] = {};
		char arr[1002] = {};
		scanf("%s", check);
		scanf("%s", arr);

		int len_check = strlen(check);
		int len_arr = strlen(arr);
		int save[1002] = {};
		int j = 0;
		for (int i = 0; i < len_arr; i++)
		{
			if (arr[i] == check[0])save[j++] = i;
		}
		int cnt = 0;
		for (int i = 0; i < j; i++)
		{
			for (int k = 0; k < len_check; k++)
			{
				if (arr[save[i] + k] != check[k])break;
				if((k+1)==len_check) cnt++;
			}
		}

		printf("#%d %d\n", i + 1, cnt);
		fill(check, check + len_check, 0);
		fill(arr, arr + len_arr, 0);


	}
	return 0;
}
