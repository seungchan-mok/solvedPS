#include <iostream>
#include <cstdio>
using namespace std;

#define MAX(a, b)  (((a) > (b)) ? (a) : (b))

int tri[501][501];
int res[501][501];

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            scanf("%d",&tri[i][j]);
        }
    }
    for(int i = 0;i<N;i++)
    {
        res[N-1][i] = tri[N-1][i];
    }
    
    for(int i = N-2; i >= 0; i--)
    {
        for(int j = 0;j < i+1;j++)
        {
            res[i][j] = MAX(res[i+1][j],res[i+1][j+1]) + tri[i][j];
        }
    }
    printf("%d",res[0][0]);
    return 0;
}
