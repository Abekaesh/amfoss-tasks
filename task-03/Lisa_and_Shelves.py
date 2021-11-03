import math
 
# function to count the divisors
def countDivisors(n) :
    count = 0
    for i in range(1, (int)(math.sqrt(n)) + 1) :
        if (n % i == 0) :
             
            # If divisors are equal,
            # count only one
            if (n / i == i) :
                count = count + 1
            else : # Otherwise count both
                count = count + 2
                 
    return count
n = int(input())
print(countDivisors(n))
