from collections import defaultdict, deque

lines = [i.strip().split("-") for i in open("aoc/2021/day-12/input.txt")]
adj = defaultdict(list)

for s, e in lines:
    adj[s].append(e)
    adj[e].append(s)

state = ("start", set(["start"]), None)
Q = deque([state])
ans = 0

while Q:
    pos, seen, twice = Q.popleft()
    if pos == "end":
        ans += 1
        continue
    for n in adj[pos]:
        new_seen = seen.copy()
        if n not in seen:
            if n.lower() == n:
                new_seen.add(n)
            Q.append((n, new_seen, twice))
        elif n in seen and twice is None and n not in ["start", "end"]:
            Q.append((n, new_seen, n))


print(ans)
