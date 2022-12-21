import fileinput

lines = [i.strip() for i in fileinput.input("aoc/2021/day-7/input.txt")]

crabs = [int(i) for i in lines[0].split(",")]

min_x = min(crabs)
max_x = max(crabs)

ans = 999999999999

for i in range(min_x, max_x + 1):
    cost = 0
    for crab in crabs:
        cost += abs(i - crab)
    ans = min(ans, cost)

print(ans)
