//3459. 승자 예측하기 D4


#include<stdio.h>

int test_case;
long long input;

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		scanf("%lld", &input);
		long long cnt = 0;

		if (input >= 1 && input <= 3)
		{
			if (input == 2 || input == 3)
				printf("#%d Alice\n", tc);
			else
				printf("#%d Bob\n", tc);
			continue;
		}

		while (input>((long long)1<<cnt))
		{
			cnt++;
		}
		//printf("cnt:%lld\n", cnt);
		int state = 1; // state = 1 : bob_line, state=0 : alice_line
		if (cnt % 2 == 1)
			state = 1;
		else
			state = 0;
		//printf("state:%d\n", state);
		long long x = 1;
		int mul_state = 1;
		int cnt_depth = 0;
		if (state == 1)
		{
			mul_state = 1;
			while ((cnt_depth+1) != cnt)
			{
				if (mul_state == 1)
					x = 2 * x + 1;
				else
					x = 2 * x;
				mul_state = mul_state ^ 1;
				//printf("%d\n", mul_state);
				cnt_depth++;
				//printf("x:%lld\n", x);
				//printf("cnt_depth:%d\n", cnt_depth);
			}
		}
		else
		{
			mul_state = 0;
			while ((cnt_depth + 1) != cnt)
			{
				if (mul_state == 1)
					x = 2 * x + 1;
				else
					x = 2 * x;
				mul_state = mul_state ^ 1;
				cnt_depth++;
				//printf("x:%lld\n", x);

			}
		}
		if (state == 1)
		{
			if (input >= x)
				printf("#%d Bob\n",tc);
			else
				printf("#%d Alice\n",tc);
		}
		else
		{
			if (input >= x)
				printf("#%d Alice\n", tc);
			else
				printf("#%d Bob\n", tc);
		}
	}
	return 0;
}
