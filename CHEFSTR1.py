for __ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    sum = 0
    for i in range(n-1):
        sum+=abs(a[i]-a[i+1])-1
    print(sum)
