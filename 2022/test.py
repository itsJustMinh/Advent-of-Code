import re

drawing = []

with open('input/test.txt') as f_in:
    for line in f_in:
        print(line[1::4])
