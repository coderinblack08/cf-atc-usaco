import sys
from collections import Counter
in_file = sys.argv[1] if len(sys.argv) > 1 else "input.txt"
polymer, rules = open(in_file).read().split("\n\n")

R = {}
for line in rules.strip().split("\n"):
    a, b = line.split(" -> ")
    R[a] = b

# keep track of counts of each pair of letters
C1 = Counter()
for i in range(len(polymer) - 1):
  C1[polymer[i] + polymer[i + 1]] += 1

for t in range(41):
  if t in [10, 40]:
    # how many times each character appears
    CF = Counter()
    for k in C1:
      CF[k[0]] += C1[k]
    # since we only take the first character, we have to account for last character on polymer
    CF[polymer[-1]] += 1
    print(max(CF.values()) - min(CF.values()))
  C2 = Counter()
  for k in C1:
    C2[k[0] + R[k]] += C1[k]
    C2[R[k] + k[1]] += C1[k]
  C1 = C2


