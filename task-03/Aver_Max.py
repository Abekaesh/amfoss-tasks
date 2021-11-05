a = int(input())
for i in range(a):
    n,k = map(int, input().split())
    array = [float(i) for i in input().split()]
    array.sort()
    if k != 0:
        print(max(abs(array[0]),abs(array[-1])))
    else:
        print(array[-1])
