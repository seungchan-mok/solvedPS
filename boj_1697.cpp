#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

#define INF 2147483647

int arr[100002];
int main()
{
    priority_queue<pair<int, int> > pq; //cost index
    
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i < 100002;i++)
    {
        arr[i] = INF;
    }
    arr[n] = 1;
    pq.push(make_pair(-1,n));
    
    while(!pq.empty())
    {
        int cur = pq.top().second; pq.pop();
        if (cur == k) break;
        int next[3];
        next[0] = cur - 1;
        next[1] = cur + 1;
        next[2] = cur * 2;
        for(int i = 0;i < 3;i++)
        {
            if(next[i]>=0 && next[i] <= 100000)
            {
                if(arr[cur]+1 < arr[next[i]])
                {
                    arr[next[i]] = arr[cur] + 1;
                    pq.push(make_pair(-arr[next[i]],next[i]));
                }
            }
        }
    }
    printf("%d",arr[k]-1);
    return 0;
}
