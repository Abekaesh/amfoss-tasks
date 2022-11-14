def total(n,k):
    a = n//k
    return k * (a * (a+1)) //2 

    
t = int(input())
for i in range(t):
    n = int(input())
    print(total(n-1,3) + total(n-1,5) - total(n-1,15))
