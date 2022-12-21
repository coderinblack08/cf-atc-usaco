import fileinput
lines = [i.strip() for i in fileinput.input("aoc/2021/day-3/input.txt")]
oxygen = 0
co2 = 0

copy = lines.copy()
for i in range(len(lines[0])):
  ones, zeros = 0, 0
  for line in copy:
    if line[i] == '1':
      ones += 1
    else:
      zeros += 1
  print(copy)
  copy = list(filter(lambda x: x[i] == "1" if ones >= zeros else "0", copy))
  if len(copy) == 1:
    oxygen = int(copy[0], 2)
    break

copy = lines.copy()
for i in range(len(lines[0])):
  ones, zeros = 0, 0
  for line in copy:
    if line[i] == '1':
      ones += 1
    else:
      zeros += 1
  copy = list(filter(lambda x: x[i] == "0" if ones > zeros else "1", copy))
  if len(copy) == 1:
    co2 = int(copy[0], 2)
    break

print(oxygen * co2)