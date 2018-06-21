//4522. 세상의 모든 팰린드롬

#include<stdio.h>
#include<string>
#include<string.h>
int test_case;

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		char input[22];
		scanf("%s", input);
		int len = strlen(input);
		bool state = true;
		for (int j = 0; j < (len/2); j++)
		{
			if (input[j] == input[len - 1 - j]) continue;
			if (input[j] == '?' || input[len - 1 - j] == '?') continue;
			else
			{
				printf("#%d Not exist\n",i+1);
				state = false;
				break;
			}
		}
		if(state == true)printf("#%d Exist\n",i+1);
	}
	return 0;
}
