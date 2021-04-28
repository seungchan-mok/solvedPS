/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct point{
    int x;
    int y;
}point;

typedef struct circle{
    point c;
    int radius;
}circle;

bool inCircle(point a,circle c)
{
    double distance = (a.x - c.c.x)*(a.x - c.c.x)+(a.y - c.c.y)*(a.y - c.c.y);
    return distance<(c.radius*c.radius);
}

int main()
{
    int test_case;
    scanf("%d",&test_case);
    for(int _i = 0;_i<test_case;_i++)
    {
        point start,end;
        scanf("%d %d %d %d",&start.x,&start.y,&end.x,&end.y);
        int circles;
        scanf("%d",&circles);
        int result = 0;
        for(int i = 0;i < circles;i++)
        {
            circle tmp;
            scanf("%d %d %d",&tmp.c.x,&tmp.c.y,&tmp.radius);
            if(inCircle(start,tmp) ^ inCircle(end,tmp))
            {
                result++;
            }
        }
        printf("%d\n",result);
    }

    return 0;
}
