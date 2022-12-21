import fileinput
from collections import defaultdict

lines = [i.strip() for i in fileinput.input("aoc/2021/day-6/input.txt")]

fish = [int(i) for i in lines[0].split(",")]

X = defaultdict(int)
for i in fish:
    if i not in X:
        X[i] = 0
    X[i] += 1

for i in range(256):
    queue = defaultdict(int)
    for k, cnt in X.items():
        if k == 0:
            queue[6] += cnt
            queue[8] += cnt
        else:
            queue[k - 1] += cnt
    X = queue

print(sum(X.values()))
