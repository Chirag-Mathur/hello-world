def pow2(num):
    if (num & 1):
        return 0
    return pow2(num//2)+1 
for _ in range(int(input())):
    ts=int(input())
    x=pow2(ts)
    ts=ts//(1<<x)
    print(ts//2)
    
    
    
