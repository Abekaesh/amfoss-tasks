def hcf(a,b):
    remainder = 1
    while remainder != 0:
        remainder = a % b
        a = b
        b = remainder
    return a

def lcm(a,b):
    c = (a * b)/hcf(a,b)
    return c

# main program
t = int(input())
for i in range(t):
    N = int(input())
    d = lcm(1,1)
    for j in range(2,N+1):
        d = lcm(d,j)
    print(int(d))
