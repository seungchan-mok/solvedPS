#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int arr[101][101][101];
int check[101][101][101];
int dxyz[6][3] = {{1,0,0},
                  {-1,0,0},
                  {0,1,0},
                  {0,-1,0},
                  {0,0,1},
                  {0,0,-1}};

int m,n,h;
typedef struct xyz{
    int x;
    int y;
    int z;
    xyz(int ix,int iy,int iz)
    {
        x = ix;
        y = iy;
        z = iz;
    }
}xyz;

bool range_check(xyz p)
{
    if(p.x >= n || p.x < 0)
        return false;
    if(p.y >= m || p.y < 0)
        return false;
    if(p.z >= h || p.z < 0)
        return false;
    return true;
}

bool will_ripe(xyz p)
{
    if(arr[p.x][p.y][p.z] == 0)
        return true;
    else return false;
}
void check_print()
{
    printf("------------------------------------\n");
    for(int k = 0;k < h;k++)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                printf("%d ",arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("------------------------------------\n");
}
int main()
{

    scanf("%d %d %d",&m,&n,&h);
    queue<xyz> q;
    
    bool all_ripen = true;
    for(int k = 0;k < h;k++)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                scanf("%d",&arr[i][j][k]);
                if(arr[i][j][k] == 1)
                {
                    all_ripen = false;
                    xyz tmp(i,j,k);
                    q.push(tmp);
                }
            }
        }
    }
    if(all_ripen)
    {
        printf("0");
        return 0;
    }
    int day = 0;
    while(!q.empty())
    {
        xyz cur = q.front();
        q.pop();
        for(int i = 0;i < 6;i++)
        {
            xyz next(cur.x + dxyz[i][0],
                    cur.y + dxyz[i][1],
                    cur.z + dxyz[i][2]);
            if(range_check(next))
            {
                if (will_ripe(next))
                {
                    q.push(next);
                    arr[next.x][next.y][next.z] = arr[cur.x][cur.y][cur.z] + 1;
                }
            }
        }
    }
    // check_print();
    bool not_ripen = false;
    int result = 1;
    for(int k = 0;k < h;k++)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(arr[i][j][k] > result)
                {
                    result = arr[i][j][k];
                }
                if(arr[i][j][k] == 0)
                {
                    not_ripen = true;
                }
            }
        }
    }
    if(not_ripen)
    {
        printf("-1");
    }
    else{
        printf("%d",result-1);
    }
    return 0;
}
