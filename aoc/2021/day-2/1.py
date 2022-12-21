with open('aoc/day-2/input.txt') as f:
  ans = 0
  data = [i.split() for i in f.read().splitlines()]
  horz = 0
  depth = 0
  for i, x in data:
    print(i, x)
    if i == "forward":
      horz += int(x)
    elif i == "up":
      depth -= int(x)
    elif i == "down":
      depth += int(x)
  print(horz * depth)