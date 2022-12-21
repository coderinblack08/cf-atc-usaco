from collections import deque

DX = [0, 1, 0, -1]
DY = [1, 0, -1, 0]
G = [[int(x) for x in list(i.strip())] for i in open("aoc/2021/day-9/input.txt")]
R = len(G)
C = len(G[0])

p2 = 0
seen = set()
B = []

for r in range(R):
    for c in range(C):
        if (r, c) not in seen and G[r][c] != 9:
            size = 0
            Q = deque()
            Q.append((r, c))
            while len(Q) > 0:
                (r, c) = Q.popleft()
                if (r, c) in seen:
                    continue
                seen.add((r, c))
                size += 1
                for i in range(4):
                    rr = r + DY[i]
                    cc = c + DX[i]
                    if 0 <= rr < R and 0 <= cc < C and G[rr][cc] != 9:
                        Q.append((rr, cc))
            B.append(size)

B.sort()
print(B[-1] * B[-2] * B[-3])
