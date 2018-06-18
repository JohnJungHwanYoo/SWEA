//1948 날짜 계산기 D2
 
#include<stdio.h>
 
 
int test_case;
int a[3] = {};
int b[3] = {};
 
int tot(int month, int day)
{
    int total = (month - 1) * 30 + day;
    //-1해야하는 경우
    if (month == 3) return total - 1;
    //0 해야 하는 경우
    else if (month == 1 || month == 4 || month == 5) return total;
    //+1
    else if (month == 2 || month == 6 || month == 7) return total + 1;
    //+2
    else if (month == 8)return total + 2;
    //+3
    else if (month == 9 || month==10)return  total + 3;
    else return total + 4;
}
 
 
int main(void)
{
    scanf("%d", &test_case);
    for (int i = 0; i < test_case; i++)
    {
 
        scanf("%d %d", &a[0], &a[1]);
        scanf("%d %d", &b[0], &b[1]);
        int ans = tot(b[0], b[1]) - tot(a[0], a[1]) +1;
 
        printf("#%d %d\n", i + 1, ans);
             
    }
    return 0;
}
