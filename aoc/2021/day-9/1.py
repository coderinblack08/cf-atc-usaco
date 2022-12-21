import fileinput

grid = [i.strip() for i in fileinput.input("aoc/2021/day-9/input.txt")]
lows = []

for i in range(len(grid)):
    for j in range(len(grid[i])):
        surrounding = [
            grid[i - 1][j] if i > 0 else " ",
            grid[i][j - 1] if j > 0 else " ",
            grid[i + 1][j] if i < len(grid) - 1 else " ",
            grid[i][j + 1] if j < len(grid[i]) - 1 else " ",
        ]
        ok = True
        for k in surrounding:
            if k != " " and int(k) <= int(grid[i][j]):
                ok = False
        if ok:
            lows.append((i, j))
