def insert_newlines(string, every=64):
    return '\n'.join(string[i:i+every] for i in range(0, len(string), every))

for __ in range(int(input())):
    n = int(input())
    o = "O"
    x = "X"
    a = ["X" for i in range(64)]
    for i in range(n):
        a[i] = "."
    a[0]=o
    print(insert_newlines("".join(a),8))
        
