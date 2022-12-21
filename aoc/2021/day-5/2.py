import fileinput
from collections import defaultdict
lines = [i.strip() for i in fileinput.input("aoc/2021/day-5/input.txt")]

grid = defaultdict(int)
for line in lines:
  a, b = line.split(" -> ")
  x1, y1 = map(int, a.split(","))
  x2, y2 = map(int, b.split(","))
  dx = x2 - x1
  dy = y2 - y1
  for i in range(max(abs(dx), abs(dy)) + 1):
    x = x1 + (1 if dx > 0 else (-1 if dx < 0 else 0)) * i
    y = y1 + (1 if dy > 0 else (-1 if dy < 0 else 0)) * i
    grid[(x, y)] += 1

print(len([i for i in grid if grid[i] > 1]))