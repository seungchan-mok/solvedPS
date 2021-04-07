#include <iostream>
#include <cstdio>
using namespace std;

#define max(a,b) (a>b?a:b)

int stairs[301];
long long int result[302];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&stairs[i]);
    }
    result[0] = stairs[0];
    result[1] = max(stairs[0] + stairs[1],stairs[1]);
    result[2] = max(stairs[0] + stairs[2],stairs[1] + stairs[2]);
    for(int i = 3;i<n;i++)
    {
        result[i] = max(result[i-2]+stairs[i], result[i-3]+stairs[i-1]+stairs[i]);
    }
    printf("%lld",result[n-1]);
    return 0;
}
