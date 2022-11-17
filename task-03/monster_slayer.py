t = int(input())
for i in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    flag = True
    for j in range(n):
        if arr[j]%min(arr)!=0:
            flag = False
            break
    if (flag):
        print('YES')
    else:
        print('NO')
