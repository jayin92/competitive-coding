import os

for item in os.listdir():
    if item[:2] == "cf" :
        os.rename(item, item[2:])