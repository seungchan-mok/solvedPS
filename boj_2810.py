n=int(input())
s=list(input())
result = 0
LL=0
for c in s:
    if c == 'S':
        result += 1
        LL=0
    else:
        LL+=1
        if LL == 2:
            result += 1
            LL = 0
result += 1
if result > n:
    result = n
print(result)
