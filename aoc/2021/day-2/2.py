with open('aoc/day-2/input.txt') as f:
  ans = 0
  data = [i.split() for i in f.read().splitlines()]
  horz = 0
  depth = 0
  aim = 0
  for i, x in data:
    if i == "forward":
      horz += int(x)
      depth += aim * int(x)
    elif i == "up":
      aim -= int(x)
    elif i == "down":
      aim += int(x)
  print(horz * depth)