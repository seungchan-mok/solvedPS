#include <iostream>
#include <cstdio>
using namespace std;
int A[1000001];
int main()
{
    int N;
    int B,C;
    scanf("%d",&N);
    for(int i =0;i<N;i++)
    {
        scanf("%d",&A[i]);
        // A[i] = 1000000;
    }
    scanf("%d %d",&B,&C);
    long long int result=0;
    int tmp;
    for(int i = 0;i < N;i++)
    {
        A[i] = A[i] - B;
        result++;
        if (A[i] <= 0)
        {
            continue;
        }
        if (A[i] % C != 0)
            result++;
        result += A[i]/C;
    }
    printf("%lld",result);
}
