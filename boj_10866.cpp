#include <stdio.h>
#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> dq;

int main()
{
    int N,tmp;
    scanf("%d",&N);
    for(int i = 0;i<N;i++)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "push_back")
        {
            scanf("%d",&tmp);
            dq.push_back(tmp);
        }
        else if(cmd == "push_front")
        {
            scanf("%d",&tmp);
            dq.push_front(tmp);
        }
        else if(cmd == "front")
        {
            if(dq.size() == 0)
            {
                printf("-1\n");
                continue;
            }
            tmp = dq.front();
            printf("%d\n",tmp);
        }
        else if(cmd == "back")
        {
            if(dq.size() == 0)
            {
                printf("-1\n");
                continue;
            }
            tmp = dq.back();
            printf("%d\n",tmp);
        }
        else if(cmd == "pop_front")
        {
            if(dq.size() == 0)
            {
                printf("-1\n");
                continue;
            }
            tmp = dq.front();
            dq.pop_front();
            printf("%d\n",tmp);
        }
        else if(cmd == "pop_back")
        {
            if(dq.size() == 0)
            {
                printf("-1\n");
                continue;
            }
            tmp = dq.back();
            dq.pop_back();
            printf("%d\n",tmp);
        }
        else if(cmd == "size")
        {
            tmp = dq.size();
            printf("%d\n",tmp);
        }
        else if(cmd == "empty")
        {
            if(dq.size() == 0)
            {
                printf("1\n");
                continue;
            }
            printf("0\n");
        }
    }
    return 0;
}
