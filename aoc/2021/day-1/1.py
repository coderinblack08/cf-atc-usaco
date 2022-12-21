with open('aoc/day-1/input.txt') as f:
  ans = 0
  data = [int(i) for i in f.read().splitlines()]
  for i in range(1, len(data)):
    if data[i] > data[i - 1]:
      ans += 1
  print(ans)