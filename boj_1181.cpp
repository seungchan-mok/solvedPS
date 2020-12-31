#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,string> > arr;
    for(int i = 0;i<n;i++)
    {
        string tmp; 
        cin >> tmp;
        int len = tmp.length();
        arr.push_back(make_pair(len,tmp));
    }
    sort(arr.begin(),arr.end());
    string pre_str = "";
    for(int i = 0;i<n;i++)
    {
        if (arr[i].second!=pre_str)
            cout << arr[i].second << "\n";
        pre_str = arr[i].second;
    }
}
