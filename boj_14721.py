n = int(input())
arr = []
for i in range(n):
    x,y = map(int,input().split())
    arr.append([x,y])

def rss(a,b):
    err = []
    for i in range(n):
        t = arr[i][1] - (a*arr[i][0] + b)
        err.append(t**2)
    # print(sum(err) / n)
    return sum(err) / n

min_res = 999999999999999
ra,rb = 0,0
for i in range(1,101):
    for j in range(1,101):
        res = rss(i,j)
        # print(res)
        if min_res > res:
            min_res = res
            ra = i
            rb = j
            
print(ra,rb)
