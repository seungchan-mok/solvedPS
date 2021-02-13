/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int nums[8];
bool checked[8];

int n;

void f(int idx, int a, int r)
{
    if (a == r)
    {
        for(int i = 0;i < n;i++)
        {
            if(checked[i]) printf("%d ",i+1);
        }
        printf("\n");
    }
    for(int i = idx;i<n;i++)
    {
        if (checked[i]) continue;
        checked[i] = true;
        f(i,a+1,r);
        checked[i] = false;
    }
}

int main()
{
    int m;
    scanf("%d %d",&n,&m);
    
    f(0,0,m);

    return 0;
}
