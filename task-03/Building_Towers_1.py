n = int(input())
a = list(map(int, input().split()))
max = 0
b = set(a)
for i in b:
  if max < a.count(i):
    max = a.count(i)
print(max,len(b))
