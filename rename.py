import os
import argparse


parser = argparse.ArgumentParser()
parser.add_argument('dir_name',type=str)
parser.add_argument('prefix',type=str)
args = parser.parse_args()

dir_name = args.dir_name
prefix = args.prefix

for item in os.listdir(dir_name):
    sz = len(prefix)
    if item[:sz] == prefix :
        os.rename(os.path.join(dir_name, item), os.path.join(dir_name, item[sz:]))