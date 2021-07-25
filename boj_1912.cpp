#include <iostream>
#include <cstdio>
using namespace std;
#define max(a,b) (a>b?a:b)


int main()
{
    int n;
    scanf("%d",&n);
    long long int result = -1000;
    long long int current = 0;
    int temp;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&temp);
        current += temp;
        if (current > result)
        {
            result = current;
        }
        if (current < 0)
        {
            current = 0;
        }
    }
    
    printf("%lld",result);
    return 0;
}
