//4050. 재관이의 대량할인

#include<stdio.h>
#include<algorithm>

using namespace std;

int test_case;
long long input_arr[100002] = {};

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int input_num = 0;
		scanf("%d", &input_num);
		int bundle_num = 0;
		long long total_sum = 0;
		bundle_num = input_num / 3;
		int rest = input_num % 3;
		//if (input_num % 3 != 0)bundle_num++;

		for (int i = 0; i < input_num; i++)
		{
			scanf("%lld", &input_arr[i]);
			total_sum = total_sum + input_arr[i];
			//printf("%d ", input_arr[i]);
		}
		//printf("\n");
		sort(input_arr, input_arr + input_num);
		long long minus = 0;
		for (int i = rest; i < input_num; i = i+3)
		{
			minus = minus + input_arr[i];
		}

		long long ans = total_sum - minus;
		printf("#%d %lld\n", i + 1, ans);
		for (int i = 0; i < input_num; i++)
		{
			input_arr[i] = 0;
		}

	}
	return 0;
}
