#include <stdio.h>

int arr[100001];
long long int sum[100002];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
        if (i>0)
        {
            sum[i+1] = sum[i] + arr[i];
        }
        else{
            sum[i+1] = arr[i];
        }
    }
    for(int i = 0;i < m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%lld\n",sum[b]-sum[a-1]);
    }
    
    return 0;
}
