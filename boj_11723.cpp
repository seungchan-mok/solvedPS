#include <iostream>
#include <string>
using namespace std;

bool check[21];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,t;
    cin >> n;
    string tmp;
    for(int i = 0;i<n;i++)
    {
        cin >> tmp;
        if(tmp == "add"){
            cin >> t;
            check[t] = true;
        }
        if(tmp == "remove"){
            cin >> t;
            check[t] = false;
        }
        if(tmp == "check"){
            cin >> t;
            if(check[t]) printf("1\n");
            else printf("0\n");
        }
        if(tmp == "toggle"){
            cin >> t;
            check[t] = !check[t];
        }
        if(tmp == "all"){
            for(int i = 0;i < 21;i++) check[i] = true;
        }
        if(tmp == "empty"){
            for(int i = 0;i < 21;i++) check[i] = false;
        }
    }

    return 0;
}
