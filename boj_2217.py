# boj 2217
N = int(input())
arr = [0] * N
for i in range(N):
  tmp = int(input())
  arr[i] = tmp
arr.sort()
result = [0] * N
for i in range(N):
  tmp = arr[i] * (N-i)
  result[i] = tmp
print(max(result))