A,B = map(int,input().split())
m = int(input())
nums = 0
digits = list(map(int,input().split()))
# print(digits)
for i in range(m):
    nums += digits[i] * (A ** (m-i-1))
    
result = []
while nums > 0:
    result.append(str(nums % B))
    # print(nums)
    nums = nums // B
result.reverse()
print(' '.join(result))
