#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pi;

vector<int> node[200003];
vector<int> cost[200003];
long long int result[200003];
int check[200001];
int main()
{
    int V,E;
    scanf("%d %d",&V,&E);
    int start;
    scanf("%d",&start);
    start = start - 1;
    for(int i = 0;i < V;i++)
    {
        result[i] = INT32_MAX;
    }
    for (int i = 0;i < E;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        node[u-1].push_back(v-1);
        cost[u-1].push_back(w);
    }
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    result[start] = 0;
    check[start] = 1;
    
    pq.push(make_pair(0,start));
    
    while(!pq.empty())
    {
        int n = pq.top().second;
        check[n] = 1;
        for(int i = 0;i < node[n].size();i++)
        {
            int next = node[n][i];
            int n_cost = cost[n][i];
            if (result[next] > result[n] + n_cost)
            {
                result[next] = result[n] + n_cost;
                pq.push(make_pair(result[next],next));
            }
        }
        pq.pop();
    }
    for(int i = 0;i < V;i++)
    {
        if(check[i] == 0)
        {
            printf("INF");
        }
        else
        {
            printf("%lld",result[i]);
        }
        printf("\n");
    }
}
