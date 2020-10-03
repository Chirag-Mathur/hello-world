from functools import reduce

for __ in range(int(input())):
    n = int(input())
    x = []
    y = []
    for i in range(4*n-1):
        a,b = map(int,input().split())
        x.append(a)
        y.append(b)
        
    xxor = reduce(lambda e, f: e ^ f, x)
    yxor = reduce(lambda e, f: e ^ f, y)
    print(xxor,yxor)
