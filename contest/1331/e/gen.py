import cv2
import numpy as np

img = cv2.imread("img.png")

l = np.zeros((64, 64))

print(l)
for i in range(64):
    for j in range(64):
        if(img[4+i*15][5+j*15][0] == 255):
            l[i][j] = 1

print(l)
for i in range(64):
    print("{", end="")
    for j in range(64):
        print(str(int(l[i][j]))+", ", end="")
    print("},")
