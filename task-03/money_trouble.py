n,m = map(int, input().split())
if n == m:
    print(n)
elif n < m:
    print(-1)
else:
    t = 0
    o = 0
    t = n//2
    a = (t+o)%m
    while a != 0 and t>=0 and o>=0:
        t-=1
        o+=2
        a = (t+o)%m
    print(t+o)
