n = list(map(int,input().split()))
def sq(n):
    return n**2
    
print(sum(list(map(sq,n)))%10)
