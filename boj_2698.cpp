#include <iostream>

using namespace std;

int dp[101][101][2];

int main()
{
    int t;
    // n = 1
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;

    for(int i = 1;i<101;i++)
    {
        for(int j = 0;j <= i;j++)
        {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
        }
    }
    scanf("%d",&t);
    int n,k;
    for(int i = 0;i<t;i++)
    {
        scanf("%d %d",&n,&k);
        printf("%lld\n",dp[n-1][k][0]+dp[n-1][k][1]);
    }

    return 0;
}
