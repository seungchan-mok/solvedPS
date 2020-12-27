#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[500001];
int times[8002];

int main()
{
    int N;
    int tmp,min_num=4001, max_num = -4001;
    long long int total = 0;
    scanf("%d",&N);
    for(int i = 0;i<N;i++)
    {
        scanf("%d",&tmp);
        arr[i] = tmp;
        times[tmp+4000]++;
        if(min_num > tmp) min_num = tmp;
        if(max_num < tmp) max_num = tmp;
        total+=tmp;
    }
    sort(arr,arr+N);
    int count=0;
    int max_times=0;
    int result_num;
    for(int i = 0;i<8002;i++)
    {
        if(max_times == times[i])
        {
            count++;
            if(count == 2)
            {
                result_num = i - 4000;
            }
        }
        if(max_times < times[i])
        {
            count=1;
            max_times = times[i];
            result_num = i - 4000;
        }
    }
    int avg = round((double)total / N);
    printf("%d\n",avg);
    printf("%d\n",arr[N/2]);
    printf("%d\n",result_num);
    printf("%d",max_num - min_num);
    return 0;
}
