import fileinput

lines = [i.strip() for i in fileinput.input("aoc/2021/day-8/input.txt")]
mp = {
    0: 6,
    1: 2,
    2: 5,
    3: 5,
    4: 4,
    5: 5,
    6: 6,
    7: 3,
    8: 7,
    9: 6,
}

ans = 0
for line in lines:
    a, b = line.split(" | ")
    for i in b.split():
        if len(i) == mp[1] or len(i) == mp[4] or len(i) == mp[7] or len(i) == mp[8]:
            ans += 1
print(ans)
