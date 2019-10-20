
def abc(a):
    if a == 1:
        return 1
    elif a == 2:
        return 2
    else:
        return abc(a-1) + abc(a-2)

try:
    while True:
        a = int(input())
        print(abc(a))
except EOFError:
    pass
