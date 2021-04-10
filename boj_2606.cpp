#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> arr[101];
int check[101];
int result;

void dfs(int s)
{
    check[s] = 1;
    result++;
    for(int i = 0;i < arr[s].size();i++)
    {
        int next = arr[s][i];
        if(!check[next])
        {
            dfs(next);
        }
    }
}

int main()
{
    int n,edge;
    scanf("%d",&n);
    scanf("%d",&edge);
    for(int i = 0;i <edge;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1);
    printf("%d",result-1);
    return 0;
}
