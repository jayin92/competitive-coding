element = []

while True:
    s = input()
    if s == "":
        continue;
    element.append(s)
    if(len(element) == 118):
        break;

print(element)