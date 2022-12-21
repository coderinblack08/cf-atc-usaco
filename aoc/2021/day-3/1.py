import fileinput
lines = [i.strip() for i in fileinput.input("aoc/2021/day-3/input.txt")]
gamma = ""
epsilon = ""
for i in range(len(lines[0])):
  ones, zeros = 0, 0
  for line in lines:
    if line[i] == '1':
      ones += 1
    else:
      zeros += 1
  if ones > zeros:
    gamma += '1'
    epsilon += '0'
  else:
    gamma += '0'
    epsilon += '1'
print(int(gamma, 2) * int(epsilon, 2))