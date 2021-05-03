#include <iostream>
#include <cstdio>
using namespace std;

int memo[51][51][51];
bool check[51][51][51];

int w(int a, int b, int c)
{
    int result;
    if(a <= 0 || b <= 0 || c <= 0) { result = 1; return 1;}
    if(check[a][b][c]) return memo[a][b][c];
    else if(a > 20 || b > 20 || c > 20) result = w(20, 20, 20);
    else if(a < b && b < c) result = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else result = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    memo[a][b][c] = result;
    check[a][b][c] = 1;
    return result;
}

int main()
{
    while(1)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }

    return 0;
}
