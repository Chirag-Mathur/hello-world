for _ in range(int(input())):
    s=list(input())
    p=list(input())
    flag=1
    ls = [chr(97+i) for i in range(26)]
    dic = dict.fromkeys(ls,0)
    for i in s:
        dic[i]+=1
    for i in p:
        dic[i]-=1
    for i in dic:
        if i<p[0] or flag==0:
            print(i*dic[i],end="")
        else:
            x=1
            while True:
                if x<len(p)-1 and p[x]==i:
                    x+=1
                else:
                    if(p[x]<i):
                        print("".join(p)+i*dic[i],end="")
                        flag=0
                    elif p[x]>i:
                        print(i*dic[i]+"".join(p),end="")
                        flag=0
                    break
    print()
