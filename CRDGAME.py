for __ in range(int(input())):
    n = int(input())
    chef = 0
    morty = 0
    for i in range(n):
        a,b = map(int, input().split())
        a = sum(map(int, list(str(a))))
        b = sum(map(int, list(str(b))))
        if a>b:
            chef+=1
        elif a<b:
            morty+=1
        else:
            chef+=1
            morty+=1
    if chef>morty:
        print(0,chef)
    elif morty>chef:
        print(1,morty)
    else:
        print(2,chef)
