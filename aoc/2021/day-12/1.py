from collections import defaultdict, deque

lines = [i.strip().split("-") for i in open("aoc/2021/day-12/input.txt")]
adj = defaultdict(list)

for s, e in lines:
    adj[s].append(e)
    adj[e].append(s)

state = ("start", set(["start"]))
Q = deque([state])
ans = 0

while Q:
    pos, seen = Q.popleft()
    if pos == "end":
        ans += 1
        continue
    for n in adj[pos]:
        if n not in seen:
            new_seen = seen.copy()
            if n.lower() == n:
                new_seen.add(n)
            Q.append((n, new_seen))
print(ans)
