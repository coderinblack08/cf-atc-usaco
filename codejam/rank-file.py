from collections import defaultdict

t = int(input())
for _ in range(t):
  n = int(input())
  s = defaultdict(int)
  for i in range(n * 2 - 1):
    for j in map(int, input().split()):
      s[j] += 1
  output = []
  for k, v in sorted(s.items()):
    if v % 2 == 1:
      output.append(str(k))
  print(" ".join(output))