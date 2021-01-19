#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int k;
    scanf("%d",&k);
    stack<int> s;
    for(int i = 0;i < k;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp == 0)
        {
            if(!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            s.push(tmp);
        }
    }
    long long int result = 0;
    while(!s.empty())
    {
        int tmp = s.top();
        result += tmp;
        s.pop();
    }
    printf("%lld",result);
}
