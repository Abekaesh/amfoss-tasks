t= int(input())
for i in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    mana = 0
    a.sort()
    if(len(set(a))==len(a)):
        a[n-1] = a[0]
        mana += 1
        a.sort()
    if 0 not in a:
        mana += len(a)
    else:
        z = a.count(0)
        mana += len(a) - z
    print(mana)
