#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int> > arr;
    for(int i = 0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        arr.push_back(make_pair(b,a));
    }
    sort(arr.begin(),arr.end());
    for(int i = 0;i < n;i++)
    {
        printf("%d %d\n",arr[i].second,arr[i].first);
    }
    return 0;
}
