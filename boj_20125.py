n=int(input())
arr = []
dxy=[[-1,-1,'_'],[-1,0,'*'],[-1,1,'_'],
    [0,-1,'*'],[0,0,'*'],[0,1,'*'],
    [1,-1,'_'],[1,0,'*'],[1,1,'_'],]

target = [['_','*','_'],
        ['*','*','*'],
        ['_','*','_']]

for i in range(n):
    arr.append(list(input()))

heart = [0,0]
for i in range(1,n-1):
    for j in range(1,n-1):
        asd = True
        for xy in dxy:
            if arr[i+xy[0]][j+xy[1]] != xy[2]:
                asd = False
                break
        if asd:
            heart = [i,j]
print(heart[0]+1,heart[1]+1)

d = 0
s = '*'
while s == '*':
    d+=1
    if heart[1]-d < 0:
        break
    s = arr[heart[0]][heart[1]-d]

print(d-1,end=' ')

d = 0
s = '*'
while s == '*':
    d+=1
    if heart[1]+d >= n:
        break
    s = arr[heart[0]][heart[1]+d]

print(d-1,end=' ')

d = 0
s = '*'
waste = [0,0]
while s == '*':
    d+=1
    if heart[0]+d >= n:
        break
    s = arr[heart[0]+d][heart[1]]
    waste = [heart[0]+d-1,heart[1]]

print(d-1,end=' ')

# ---
d = 0
s = '*'
while s == '*':
    d+=1
    if waste[0]+d >= n:
        break
    s = arr[waste[0]+d][waste[1]-1]

print(d-1,end=' ')

d = 0
s = '*'
while s == '*' and waste[0]+d < n:
    d+=1
    if waste[0]+d >= n:
        break
    s = arr[waste[0]+d][waste[1]+1]

print(d-1,end=' ')

