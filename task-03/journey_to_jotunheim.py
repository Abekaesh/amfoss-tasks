t = int(input())
for i in range(t):
    x = int(input())
    keys = [int(c) for c in input().split()]
    if keys[x-1]!=0:
        s = keys[x-1]
        if keys[s-1]!=0:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
