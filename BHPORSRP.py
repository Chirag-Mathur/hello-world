for _ in range(int(input())):
    a=input()
    a=a.lower()
    if 'berhampore' in a:
        if 'serampore' in a:
            print('Both')
        else:
            print('GCETTB')
    elif 'serampore' in a:
        print('GCETTS')
    else:
        print('Others')
        
