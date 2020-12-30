#include <iostream>
#include <cstdio>
using namespace std;

long long int fac[11] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%lld",fac[n] / (fac[k]*fac[n-k]));
    
    return 0;
}
