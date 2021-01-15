#include <iostream>
#include <cstdio>
using namespace std;

int arr[100001];

int main()
{
    for(int i = 2;i < 101;i++)
    {
        int mul = 2;
        int tmp = i * mul;
        while(tmp < 100001)
        {
            mul++;
            arr[tmp] = 1;
            tmp = i * mul;
            // cout << tmp << endl;
        }
    }
    int test_case;
    scanf("%d",&test_case);
    for(int i = 0;i<test_case;i++)
    {
        int target;
        scanf("%d",&target);
        int step=target/2;
        int a=0,b=target;
        while(step>=0)
        {
            // cout << arr[step] << endl;
            if(arr[step] == 1)
            {
                step--;
                continue;
            }
            int mstep = target - step;
            if(arr[mstep] == 0)
            {
                // cout << step << " " << mstep << endl;
                if((b-a) > (mstep - step))
                {
                    b = mstep;
                    a = step;
                }
            }
            step--;
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}
