// 1493. 수의 새로운 연산


//1. 런타임에러난 첫 번째 풀이
/*
#include<stdio.h>
#include<algorithm>

using namespace std;

int test_case;
int board[150][150];

pair<int,int> find_coordinate(int a)
{
	for (int i = 1; i <= 142; i++)
	{
		for (int j = 1; j <= 142; j++)
		{
			if (board[j][i] == a)
				return { j,i };
		}
	}
}

int main(void)
{
	scanf("%d", &test_case);

	//1사분면 격자점 위치 정리
	int whole_cnt = 1;
	for (int j = 1; j <= 142; j++)
	{
		int cnt = 0;
		while((j-cnt)!=0)
		{
			board[1 + cnt][j - cnt] = whole_cnt++;
			cnt++;
		}
	}

	//for (int i = 1; i <= 10; i++)
	//{
	//	for (int j = 1; j <= 10; j++)
	//	{
	//		printf("%d ", board[j][i]);
	//	}
	//	printf("\n");
	//}

	for (int i = 0; i < test_case; i++)
	{

		int P, Q;
		scanf("%d %d", &P, &Q);
		//printf("%d %d\n", P, Q);
		int x = find_coordinate(P).first + find_coordinate(Q).first;
		int y = find_coordinate(P).second + find_coordinate(Q).second;

		//printf("P:%d %d\n Q:%d %d\n", find_coordinate(P).first, find_coordinate(P).second, find_coordinate(Q).first, find_coordinate(Q).second);

		printf("#%d %d\n", i + 1, board[x][y]);
	}
	return 0;
}
*/



//풀긴 풀었지만 오래걸린 풀이

/*
 
#include<stdio.h>
#include<algorithm>
 
using namespace std;
 
int test_case;
//int board[150][150];
 
//pair<int,int> find_coordinate(int a)
//{
//  for (int i = 1; i <= 142; i++)
//  {
//      for (int j = 1; j <= 142; j++)
//      {
//          if (board[j][i] == a)
//              return { j,i };
//      }
//  }
//}
 
int main(void)
{
    scanf("%d", &test_case);
 
    //1사분면 격자점 위치 정리
    int whole_cnt = 1;
    int coord_save[3][50000] = {};
    for (int j = 1; j <= 300; j++) 
    {
        int cnt = 0;
        while((j-cnt)!=0)
        {
            coord_save[0][whole_cnt] = whole_cnt;
            coord_save[1][whole_cnt] = (1 + cnt);
            coord_save[2][whole_cnt] = (j - cnt);
            whole_cnt++;
            //board[1 + cnt][j - cnt] = whole_cnt++;
            cnt++;
        }
    }
 
 
 
    for (int i = 0; i < test_case; i++)
    {
 
        int P, Q;
        scanf("%d %d", &P, &Q);
        int x = coord_save[1][P] + coord_save[1][Q];
        int y = coord_save[2][P] + coord_save[2][Q];
        //int check_cnt = 1;
        int check_cnt=0;
        //printf("x:%d y:%d\n", x, y);
        for ( check_cnt = 1; check_cnt <= 50000; check_cnt++)
        {
            if (coord_save[1][check_cnt] != x || coord_save[2][check_cnt] != y)continue;
            else if (coord_save[1][check_cnt] == x && coord_save[2][check_cnt] == y)break;
        }

        printf("#%d %d\n", i + 1, check_cnt);
    }
    return 0;
}

*/

//훌륭한 다른 사람 풀이

#include <cstdio>
//cstudio는 어떤 것?
 
struct Position
{
    int xPos;
    int yPos;
};
 
int p;
int q;
 
 
//이 함수가 좀 이해가 안감. order 수식 도출 어떻게 한건지? 
int ConvertToOrder(Position pos)
{
    int level = pos.xPos + pos.yPos - 2;
 
    int order = (level + 1) * (level / 2) + pos.xPos;
 
    if (level % 2 != 0)
        order += (level / 2) + 1;
 
    return order;
}
 
Position ConvertToPos(int order)
{
    int level = 0;
    int count = 0;
    for (int i = 1;; i++)
    {
        count += i;
        level++;
        if (count >= order)
            break;
    }
 
    Position pos;
    pos.yPos = level;
    pos.xPos = 1;
 
    int n = order - ConvertToOrder(pos);
 
    pos.yPos -= n;
    pos.xPos += n;
 
    return pos;
}
 
 
int Logic()
{
    Position pos1;
    Position pos2;
 
    pos1 = ConvertToPos(p);
    pos2 = ConvertToPos(q);
 
    pos1.xPos += pos2.xPos;
    pos1.yPos += pos2.yPos;
 
    return ConvertToOrder(pos1);
}
 
int main()
{
    int input;
    scanf("%d", &input);
 
    for (int testCase = 1; testCase <= input; testCase++)
    {
        scanf("%d %d", &p, &q);
        printf("#%d %d\n", testCase, Logic());
    }
 
    return 0;
}
