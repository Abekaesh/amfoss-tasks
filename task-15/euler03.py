t = int(input())
for i in  range(t):
    num = int(input())
    temp = num
    max_prime = 0
    flag = 2
    while flag**2 <= temp:
        if temp % flag == 0:
            temp = temp / flag
            max_prime = flag
        else:
            flag += 1
    if temp > max_prime:
        max_prime = temp
    print(int(max_prime))  
