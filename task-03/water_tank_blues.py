t = int(input())
for i in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    water = []
    a.pop()
    if a.count(0) == len(a):
        print(0)
        continue
    start = 0
    for y in a:
        if y!=0:
            start = a.index(y)
            break
    a = a[start:]
    ans = sum(a) + a.count(0)
    print(int(ans))
