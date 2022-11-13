a = int(input())
conv = 0
while a>=10:
    temp = a
    s = 0
    for i in range(len(str(a))):
        s += temp%10
        temp = temp//10
    a = s
    conv += 1
print(conv)
