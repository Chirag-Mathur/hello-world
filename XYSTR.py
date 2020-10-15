for __ in range(int(input())):
    s=list(input())
    xPos = [ i for i in range(len(s)) if s[i] == 'x' ]
    yPos = [ i for i in range(len(s)) if s[i] == 'y' ]
    c=0
    
    for i in yPos:
        if i-1 in xPos:
            c+=1
            xPos.remove(i-1)
        elif i+1 in xPos:
            c+=1
            xPos.remove(i+1)
    print(c)
