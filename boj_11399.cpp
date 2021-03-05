#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int cost_times[1001];
long long int summations[1001];

int main()
{
    int n,tmp;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&cost_times[i]);
    }
    sort(cost_times,cost_times+n);
    long long int result = 0;
    for(int i = 1;i < n+1;i++)
    {
        summations[i] = summations[i-1] + cost_times[i-1];
        result += summations[i];
    }
    printf("%lld",result);
    return 0;
}
