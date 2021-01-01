#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int e,s,m,y = 1;
    int en = 1,sn = 1,mn = 1;
    scanf("%d %d %d",&e,&s,&m);
    
    while(1)
    {
        if(e == en && s == sn && m == mn)
        {
            break;
        }
        en++;sn++;mn++;y++;
        if(en > 15) en = 1;
        if(sn > 28) sn = 1;
        if(mn > 19) mn = 1;
    }
    printf("%d",y);
    return 0;
}
