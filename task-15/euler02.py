import sys
t = int(sys.stdin.readline())
for i in range(t):
    n = int(sys.stdin.readline())
    f,s = 1,2
    etotal = 0
    while s < n:
        th = f + s
        f,s=s,th
        if f%2 == 0:
            etotal += f
    print(etotal)
