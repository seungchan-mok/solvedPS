#include <iostream>
#include <queue>
using namespace std;

#define INFINITY 99999999999

int chess_board[301][301];
int cost[301][301];

int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};

int l;
int gx,gy;

void initialize(int size)
{
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < size;j++)
        {
            chess_board[i][j] = 0;
            cost[i][j] = INFINITY;
        }
    }
}

bool range_check(int x,int y)
{
    if(x >= 0 && y >= 0)
    {
        if(x < l && y < l)
            return true;
    }
    return false;
}

void bfs(int x,int y)
{
    queue<pair<int,int> > Q;
    Q.push(make_pair(x,y));
    cost[x][y] = 0;
    while(!Q.empty())
    {
        x = Q.front().first; y = Q.front().second;
        Q.pop();
        if(x == gx && y == gy)
        {
            break;
        }
        for(int i = 0;i<8;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(range_check(nx,ny))
            {
                if(cost[nx][ny] > cost[x][y] + 1)
                {
                    cost[nx][ny] = cost[x][y] + 1;
                    Q.push(make_pair(nx,ny));
                    // cout << "push! " << nx << " " << ny << endl;
                }
            }
        }
    }
}

int main()
{
    int test_case;
    scanf("%d",&test_case);
    for(int i = 0;i < test_case;i++)
    {
        scanf("%d",&l);
        initialize(l);
        int x,y;
        scanf("%d %d",&x,&y);
        scanf("%d %d",&gx,&gy);
        bfs(x,y);
        printf("%d\n",cost[gx][gy]);
    }

    return 0;
}
