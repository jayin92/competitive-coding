n = int(input())
# n = 10 ** 500000
# print(math.log10(n) / math.log10(6))
l = 0
r = 650000
while r - l != 1:
    mid = (l + r) // 2
    x = 6 ** mid
    # print(l, r)
    if x > n:
        r = mid
    elif x < n:
        l = mid
    else:
        print(mid+1)
        exit(0)
print(r)