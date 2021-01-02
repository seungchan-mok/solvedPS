#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

#define MIN(a,b) (a < b ? a : b)

int memo[100001];

int main()
{
    int n;
    scanf("%d",&n);
    memo[1] = 1;
    memo[0] = 1;
    for(int i = 2;i<=n;i++) 
    {
        memo[i] = 9999999;
        int sq = (int)sqrt(i);
        if (sq*sq == i) memo[i] = 1;
    }
    
    for(int i = 1;i <= n;i++)
    {
        int sq = (int)sqrt(i);
        for(int j = sq;j>=1;j--)
        {
            int s = i - j*j;
            memo[i] = MIN(memo[i],(memo[s] + memo[j*j]));
        }
    }
    printf("%d",memo[n]);
    return 0;
}
