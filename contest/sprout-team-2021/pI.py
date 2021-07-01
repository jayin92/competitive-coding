t = int(input())

for i in range(t):
    l = input().split(" ")
    a = int(l[0])
    b = int(l[1])
    if a == 1 and b != 0:
        print('Yes')
    else:
        print('No')