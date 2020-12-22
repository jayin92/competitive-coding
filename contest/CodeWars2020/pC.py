a = input("")

a = a.split(" ")
# print(a)

b = a[0]
c = a[1]

aa = b[1:-1]
aa = aa.split(",")

bb = c[1:-1]
bb = bb.split(",")

# print(aa, bb)

res = []

hold = 0
if(len(aa) < len(bb)):
    aa, bb = bb, aa
for i in range(len(aa)):
    tmp = int(aa[i]) + hold
    if(i < len(bb)):
        tmp += int(bb[i])
    res.append(tmp % 10)
    hold = tmp // 10

if hold != 0:
    res.append(hold)

print("[", end="")
for i in range(len(res)):
    print(res[i], end="")
    if i != len(res) - 1:   
        print(", ", end="")
print("]")