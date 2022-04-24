for i in range(9):
    for j in range(9):
        print(f"{i}, {j}, max: {min(i+j, 8) + min(0, 8-i-j)}, min: {abs(i-j)}")