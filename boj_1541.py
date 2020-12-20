s = input()
result = 0
num_s = ''
is_m = False
for ch in s:
  if ch == '-':
    if is_m:
      result = result - int(num_s)
    else:
      result = result + int(num_s)
    is_m = True
    num_s = ''
  elif ch == '+':
    if is_m:
      result = result - int(num_s)
    else:
      result = result + int(num_s)
    num_s = ''
  else:
    num_s = num_s + ch
if is_m:
  result = result - int(num_s)
else:
  result = result + int(num_s)
print(result)
