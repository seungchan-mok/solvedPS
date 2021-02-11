#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > arr;
bool checked[100001];
int root[100001];

void dfs(int x)
{
    checked[x] = 1;
    for(int i=0;i<arr[x].size();i++)
    {
        int n = arr[x][i];
        if(!checked[n])
        {
            root[n] = x;
            dfs(n);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    
    vector<int> tmp;
    arr.assign(n,tmp);
    int a,b;
    for(int i = 0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
    }
    checked[0]=1;
    dfs(0);
    for(int i = 1;i<n;i++)
    {
        printf("%d\n",root[i]+1);
    }
    return 0;
}
