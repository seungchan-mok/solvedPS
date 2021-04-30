#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int arr[301][301];
int new_arr[301][301];
bool check[301][301];
int n,m;

void check_arr()
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    cout << "----------" << endl;
}

void check_reset()
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            check[i][j] = 0;
            new_arr[i][j] = 0;
        }
    }
}

void dfs(int x,int y)
{
    check[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0&&ny>=0&&nx<n&&ny<m)
        {
            if(arr[nx][ny] > 0 && check[nx][ny] == 0)
            {
                dfs(nx,ny);
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    queue<pair<int,int> > Q;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    // check_arr();
    int step = 0;
    int first_run = 0;
    while(1)
    {
        // check divide
        int block = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(arr[i][j] > 0 && check[i][j] == 0)
                {
                    block++;
                    dfs(i,j);
                    Q.push(make_pair(i,j));
                }
            }
        }
        if(block == 0)
        {
            step = 0;
            break;
        }
        if(block > 1 && first_run == 0)
        {
            step = 1;
            break;
        }
        else
        {
            first_run = 1;
        }
        if(block > 1)
        {
            break;
        }
        step++;
        check_reset();
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                int near = 0;
                if(arr[i][j] > 0)
                {
                    for(int d = 0;d < 4;d++)
                    {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if(nx>=0&&ny>=0&&nx<n&&ny<m)
                        {
                            if(arr[nx][ny] == 0)
                            {
                                near++;
                            }
                        }
                    }
                    new_arr[i][j] = arr[i][j] - near;
                    if(new_arr[i][j] < 0)
                    {
                        new_arr[i][j] = 0;
                    }
                }
                else{
                    new_arr[i][j] = 0;
                }
            }
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                arr[i][j] = new_arr[i][j];
            }
        }
        // check_arr();
    }
    printf("%d",step);
    return 0;
}
