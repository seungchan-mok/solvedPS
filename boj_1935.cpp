#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int alphabet[26];

bool is_operator(char a)
{
    if(a == '+' || a == '-' || a == '*' || a == '/')
        return true;
    return false;
}

double get_val(char x)
{
    return (double)alphabet[x - 'A'];
}

int main(void)
{
    int n;
    char str[104];
    int ch;
    int idx = 0;

    scanf("%d",&n);
    scanf("%s ",str);

    // printf("%s\n",str);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&alphabet[i]);
    }
    // printf("%d string : %s\n",idx,str);
    stack<double> st;
    int i = 0;
    while(!(str[i] == '\0'))
    {
        if(is_operator(str[i]))
        {
            double a,b;
            a = st.top(); st.pop();
            b = st.top(); st.pop();
            // printf("%lf %lf %c\n",a,b,str[i]);
            if (str[i] == '+') st.push(a + b);
            if (str[i] == '-') st.push(b - a);
            if (str[i] == '*') st.push(a * b);
            if (str[i] == '/') st.push(b / a);
            // cout << st.top() << endl;
        }
        else
        {
            double val = get_val(str[i]);
            // printf("%lf\n",val);
            st.push(val);
        }
        i++;
    }
    printf("%.2f",st.top());
    return 0;
}
