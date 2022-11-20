n = int(input())
points=list()
for i in range(n):
    x,y=map(int, input().split())
    points.append([x,y])
ans = 0
for i in range(n):
    a,b = points[i]
    e = 0
    for j in range(n):
        c,d = points[j]
        if (c>a or c<a) and d == b:
            e += 1
        if c == a and (d>b or d<b):
            e+=1
    if e>=4:
        ans += 1
print(ans)
