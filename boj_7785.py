n=int(input())
arr = []
for i in range(n):
    name,cmd = input().split()
    if cmd == "enter":
        arr.append(name)
    if cmd == "leave":
        arr.remove(name)
arr.sort(reverse=True)
for c in arr:
    print(c)
    
