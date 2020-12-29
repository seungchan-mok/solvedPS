#include <iostream>
#include <string>
using namespace std;

#define MAX(a,b) (a > b ? a : b)

string add(string a, string b)
{
    int len = MAX(a.length(), b.length());
    string result = "";
    int post = 0;
    int numA,numB;
    for(int i = 1;i < len+1;i++)
    {
        numA = 0;
        numB = 0;
        if(i < a.length()+1) numA = a[a.length() - i] - '0';
        if(i < b.length()+1) numB = b[b.length() - i] - '0';
        int s = numA + numB + post;
        if (s >= 10)
        {
            post = 1;
        }
        else
        {
            post = 0;
        }
        char ch = (s % 10) + '0';
        result = ch + result;
    }
    if(post == 1)
    {
        result = '1' + result;
    }
    return result;
}

int main()
{
    string a,b;
    cin >> a >> b;
    string result = add(a,b);
    cout << result;
    return 0;
}
