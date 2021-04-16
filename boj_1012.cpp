#include <iostream>
#include <cstdio>
using namespace std;

int arr[51][51];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int m,n;
void reset()
{
    for(int i = 0;i < 51;i++)
    {
        for(int j = 0;j < 51;j++)
            arr[i][j] = 0;
    }
}

void dfs(int x,int y)
{
    arr[x][y] = 0;
    for(int i = 0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >=0 && nx < m && ny >=0 && ny < n)
        {
            if(arr[nx][ny] == 1)
            {
                dfs(nx,ny);
            }
        }
    }
}

int main()
{
    int test_case;
    scanf("%d",&test_case);
    for(int i__ = 0;i__ < test_case;i__++)
    {
        int k;
        int x,y;
        scanf("%d %d %d",&m,&n,&k);
        for(int i = 0;i < k;i++)
        {
            scanf("%d %d",&x,&y);
            arr[x][y] = 1;
        }
        int result=0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(arr[i][j] == 1)
                {
                    dfs(i,j);
                    result++;
                }
            }
        }
        printf("%d\n",result);
    }
    
    return 0;
}
