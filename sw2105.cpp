//2105. [모의 SW 역량테스트] 디저트 카페
 
#include<stdio.h>
#include<string>
 
using namespace std;
 
 
int test_case;
int N;
int map[22][22];
int isVisited[101];
int result = -1;
bool state = true;
 
void isVisited_init(void)
{
    fill(isVisited, isVisited + 101, 0);
    return;
}
 
void init(void)
{
    result = -1;
    state = true;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            map[i][j] = 0;
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
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }
 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int ne = 1; ne <= N; ne++) // 북동변
                {
 
                    for (int se = 1; se <= N; se++) // 남동변
                    {
                        isVisited_init();
                        state = true;
                        if (((i + ne + se) < N) && ((j + ne) < N) && ((j + ne - se) >= 0) && (j-se)>=0)
                        //if (((i + ne + se) < N) && ((j + ne) < N))
                        {
                         
                            //if (ne == 2 && se == 2)printf("@#$");
                            //isVisited initializaing
 
                            //남동쪽으로 이동
                            int move1 = 0;
                            for (move1 = 1; move1 <= ne; move1++)
                            {
                                if (isVisited[map[i + move1][j + move1]] == 0)
                                {
                                    isVisited[map[i + move1][j + move1]] = 1;
                                }
                                else
                                {
                                    state = false;
                                    break;
                                }
                            }
                            if (state == false) continue;
                             
                            //남서쪽으로 이동
                            int move2 = 0;
                            for (move2 = 1; move2 <= se; move2++)
                            {
                                if (isVisited[map[i + ne+move2][j + ne-move2]] == 0)
                                {
                                    isVisited[map[i + ne+move2][j + ne-move2]] = 1;
                                }
                                else
                                {
                                    state = false;
                                    break;
                                }
                            }
                            if (state == false) continue;
 
                            //북서쪽으로 이동
                            int move3 = 0;
                            for (move3 = 1; move3 <= ne; move3++)
                            {
                                if (isVisited[map[i + ne + se - move3][j + ne - se - move3]] == 0)
                                {
                                    isVisited[map[i + ne + se - move3][j + ne - se - move3]] = 1;
                                }
                                else
                                {
                                    state = false;
                                    break;
                                }
                            }
                            if (state == false) continue;
 
                            //제자리로 이동
                            int move4 = 0;
                            for (move4 = 1; move4 <= se; move4++)
                            {
                                if (isVisited[map[i + se - move4][j - se + move4]] ==0)
                                {
                                    isVisited[map[i + se - move4][j - se + move4]] = 1;
                                }
                                else
                                {
                                    state = false;
                                    break;
                                }
                            }
                            if (state == false) continue;
 
                            int cur_result = 2 * (se + ne);
                            if (cur_result >= result)
                            {
                                result = cur_result;
                                //printf("result:%d, i:%d, j:%d se:%d, ne:%d\n",result,i,j, se, ne);
                            }
                        }
                        //else if (((i + ne + se) < N) && ((j + ne) < N) )
                        //  printf("i:%d, j:%d, ne:%d, se:%d\n",i,j, ne, se);//((i + ne) < N) && //((j + ne - se) >= 0) &&//&&  ((j - se) >= 0)
                         
                    }
                }
            }
        }
        printf("#%d %d\n", tc, result);
 
 
    }
    return 0;
}
