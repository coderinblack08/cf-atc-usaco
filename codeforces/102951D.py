from bisect import bisect_left

n, q = map(int, input().split())

updates = []
indices = []
queries = []
for i in range(n):
  l, r, v = map(int, input().split())
  indices += [l, r]
  updates.append(((l, r), v))

for i in range(q):
  l, r = map(int, input().split())
  indices += [l, r]
  queries.append((l, r))

indices.sort()
indices = list(set(indices))

diff = []
widths = []
interval = []

# corodinate compression
for i in range(n):
  a = updates[i]
  diff[bisect_left(indices, a[0][0]) + 1] += a[1]
  diff[bisect_left(indices, a[0][1]) + 1] -= a[1]

for i in range(len(indices) - 1):
  widths[i + 1] = indices[i + 1] - indices[i]

for i in range(1, len(indices)):
  interval[i] = interval[i - 1] + diff[i]

for i in range(1, len(indices)):
  psum[i] = psum[i - 1] + interval[i] * widths[i]

for i in range(q):
  print(psum[bisect_left(indices, queries[i][1])] - psum[bisect_left(indices, queries[i][0]) - 1])