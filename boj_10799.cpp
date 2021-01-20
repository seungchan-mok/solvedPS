#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int s=0;
    long long int result = 0;
    for (int i = 0;i < str.length();i++)
    {
        char ch = str[i];
        if(ch == '(')
        {
            s++;
        }
        else if(ch == ')')
        {
            if(str[i-1] == '(')
            {
                result = (s - 1) + result;
                s--;
            }
            else
            {
                result++;
                s--;
            }
        }
    }
    printf("%lld",result);
    return 0;
}
