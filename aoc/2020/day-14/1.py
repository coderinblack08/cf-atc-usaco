import re

N = 36
mask = ""
mem = [0] * 1000000

def use_mask(mask, val):
  ret = "0" * N
  binary = bin(val)[2:]
  binary = "0" * (N - len(binary)) + binary
  for i in range(len(binary) - 1, -1, -1):
    if mask[i] == "X":
      ret = ret[:i] + binary[i] + ret[i+1:]
    else:
      ret = ret[:i] + mask[i] + ret[i+1:]
  return int(ret, 2)

with open("aoc/2020/day-14/input.txt") as f:
  lines = f.read().splitlines()
  for line in lines:
    if line.startswith("mask"):
      mask = line[7:]
    else:
      op, val = line.split(" = ")
      address = int(re.findall(r'\d+', op)[0])
      print(address, val)
      mem[address] = use_mask(mask, int(val))

print(sum(mem))
