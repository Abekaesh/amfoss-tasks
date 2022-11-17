n,m = map(int, input().split())
c = 0
if n==m:
    print(0)
    exit()
if m%n!=0:
    print(-1)
    exit()
q = int(m/n)
while q >1:
    if q%6 == 0:
        c += 2
        q =q/6
    elif q%3 == 0:
        c += 1
        q = q/3
    elif q%2 == 0:
        c += 1
        q = q/2
    else:
        print(-1)
        exit()
print(c)
