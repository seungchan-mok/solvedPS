#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str="";
    while(1)
    {
        getline(cin, str);
        // cout << str << endl;
        if (str == ".")
        {
            break;
        }
        stack<char> s;
        bool result = true;
        for(int i = 0;i<str.length(); i++)
        {
            char ch = str[i];
            if (ch == '(' || ch == '[')
            {
                s.push(ch);
            }
            if (ch == ')' || ch == ']')
            {
                if (s.empty()){ result = false; break; }
                bool check = false;
                if (s.top() == '(' && ch == ')')
                {
                    check = true;
                }
                if (s.top() == '[' && ch == ']') 
                {
                    check = true;
                }
                s.pop();
                if (!check) 
                {
                    result = false;
                    break;
                }
            }
        }
        if(!s.empty())result = false;
        if(result) printf("yes\n");
        else printf("no\n");
    }
}
