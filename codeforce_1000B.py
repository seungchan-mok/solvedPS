import sys
n,m = map(int,sys.stdin.readline().rstrip().split())
a = list(map(int,sys.stdin.readline().rstrip().split()))
a = [0] + a + [m]

switch = True

s = [0] * len(a)
for i in range(1,len(a)):
    s[i] = s[i-1] + switch*(a[i] - a[i-1])
    switch = not switch
result = s[-1]
for i in range(1,len(a)):
    result = max(result, s[i] + m - a[i] - (s[-1] - s[i] + 1))

print(result)
