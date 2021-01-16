#include <cstdio>
#include <cmath>
using namespace std;

int arr[1000001];

int main()
{
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 2;i < sqrt(1000001);i++)
    {
        int mul = 2;
        int tmp = i * mul;
        while(tmp < 1000001)
        {
            mul++;
            arr[tmp] = 1;
            tmp = i * mul;
        }
    }
    int test_case;
    while(1)
    {
        int target;
        scanf("%d",&target);
        if (target == 0)
        {
            break;
        }
        int step=3;
        int a=0,b=0;
        bool isWrong = true;
        while(step < target)
        {
            if(arr[step] == 1)
            {
                step++;
                continue;
            }
            int mstep = target - step;
            if(arr[mstep] == 0)
            {
                isWrong = false;
                b = mstep;
                a = step;
                break;
            }
            step++;
        }
        if(isWrong)
        {
            printf("Goldbach's conjecture is wrong.\n");
        }
        else{
            printf("%d = %d + %d\n",target,a,b);
        }
    }
    return 0;
}
