import fileinput
lines = [i.strip() for i in fileinput.input("aoc/2021/day-5/input.txt")]

points = set()
ans = set()

for line in lines:
  a, b = line.split(' -> ')
  x1, y1 = map(int, a.split(','))
  x2, y2 = map(int, b.split(','))
  if x1 == x2:
    min_y = min(y1, y2)
    max_y = max(y1, y2)
    for y in range(min_y, max_y+1):
      if (x1, y) in points:
        ans.add((x1, y))
      else:
        points.add((x1, y))
  elif y1 == y2:
    min_x = min(x1, x2)
    max_x = max(x1, x2)
    for x in range(min_x, max_x+1):
      if (x, y1) in points:
        ans.add((x, y1))
      else:
        points.add((x, y1))

print(len(ans))