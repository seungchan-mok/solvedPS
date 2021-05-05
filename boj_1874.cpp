#include <iostream>
#include <stack>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    stack<int> st;
    int n,cur=1;
    scanf("%d",&n);
    bool able = true;
    vector<char> op;
    for(int i = 0;i < n;i++)
    {
        int target;
        scanf("%d",&target);
        while(cur <= target)
        {
            st.push(cur);
            op.push_back('+');
            // cout << "tar " << target << ", cur " << cur << endl;
            cur++;
        }
        if(st.top() == target)
        {
            op.push_back('-');
            // cout << "pop -" << endl;
            st.pop();
        }
        if(!able) break;
    }
    // cout << "stack " << st.size() << endl;
    if(st.size() == 0)
    {
        for(int i = 0;i < op.size();i++)
        {
            printf("%c\n",op[i]);
        }
    }
    else{
        printf("NO");
    }
    return 0;
}
