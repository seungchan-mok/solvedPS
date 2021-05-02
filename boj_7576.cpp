#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int m,n;
int arr[1001][1001];

int main()
{
    queue<pair<int,int> > Q;
    scanf("%d %d",&m,&n);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            scanf("%d",&arr[i][j]);
            if (arr[i][j] == 1)
            {
                Q.push(make_pair(i,j));
            }
        }
    }
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int i = 0;i < 4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx < n && ny >= 0 && ny < m)
            {
                if(arr[nx][ny] == 0)
                {
                    Q.push(make_pair(nx,ny));
                    arr[nx][ny] = arr[x][y] + 1;
                }
            }
        }
    }
    
    int result = -1;
    bool flag = false;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(arr[i][j] == 0)
            {
                result = -1;
                flag = true;
                break;
            }
            if(arr[i][j] > result)
            {
                result = arr[i][j];
            }
        }
        if(flag) break;
    }
    if(result > 0)
    {
        printf("%d",result-1);
    }
    else{
        printf("-1");
    }
    return 0;
}
