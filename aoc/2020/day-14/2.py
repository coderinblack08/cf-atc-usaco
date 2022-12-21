import fileinput

mask  = ""
mem = {}
lines = list(fileinput.input())

def parse_with_mask(idx, mask):
  new_idx = 0
  floating = []
  for i, bit in enumerate(reversed(mask)):
    if bit == "X":
      floating.append(i)
    elif bit == "1":
      new_idx += 2 ** i
    else:
      new_idx += idx & (2 ** i)

for line in lines:
  line = line.strip()
  if line.startswith("mask"):
    mask = line[7:]
  else:
    idx, _, val = line.split()