//3131. 100만 이하의 모든 소수

#include<stdio.h>

int arr[1000002];

int main(void)
{
	for (int i = 2; i <= 1000000; i++)
	{
		if (arr[i] == 1)continue;
		printf("%d ", i);
		for (int j = i+i; j <= 1000000; j=j+i)
		{
			if (arr[i] == 1)continue;

			arr[j] = 1;
		}
	}
	return 0;
}
