#include <iostream>
#include <cstdio>
using namespace std;
#define max(a,b) (a>b?a:b)

int arr[100004];
int result[100004];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 3;i<n+3;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i = 3;i < n+3;i++)
    {
        result[i] = max(result[i-3]+arr[i-1],
                    result[i-2]) + arr[i];
        result[i] = max(result[i-1],result[i]);
    }
    printf("%d",max(result[n+2],result[n+1]));
    return 0;
}
