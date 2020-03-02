import argparse, os
from shutil import copyfile

parser = argparse.ArgumentParser()
parser.add_argument('online_judge', type=str)
parser.add_argument('problem_id', type=str)
args = parser.parse_args()

dir_name = args.online_judge
file_name = args.problem_id + '.cpp'

if os.path.exists(dir_name):
    copyfile('template.cpp', os.path.join(dir_name, file_name))
    print("File " + os.path.join(dir_name, file_name) + ' created')
else :
    print("Directory doesn't exist")