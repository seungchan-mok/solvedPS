#include <iostream>
#include <cstdio>
using namespace std;

int N;

int main()
{
    scanf("%d",&N);
    int t = 2;
    while(N != 1)
    {
        while(t <= N)
        {
            if(N % t == 0)
            {
                N = N / t;
                printf("%d\n",t);
                break;
            }
            else
            {
                t++;
            }
        }
    }
    return 0;
}
