#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int arr[100002];

bool bi_search(int st, int end, int key)
{
    int mid = ((end + st) / 2) +1;
    if (arr[st] == key) return true;
    if (arr[end] == key) return true;
    if (arr[mid] == key) return true;
    if (st>=end) return false;
    if (arr[mid] < key)
    {
        return bi_search(mid+1,end-1,key);
    }
    if (arr[mid] > key)
    {
        return bi_search(st+1,mid-1,key);
    }
    return false;
}

int main()
{
    int n;
    int tmp;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int m;
    scanf("%d",&m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d",&tmp);
        printf("%d\n",bi_search(0,n-1,tmp));
    }
    return 0;
}
