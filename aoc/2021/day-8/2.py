import itertools

input = [i.strip() for i in open("aoc/2021/day-8/input.txt")]

digits = {
    0: "abcefg",
    1: "cf",
    2: "acdeg",
    3: "acdfg",
    4: "bcdf",
    5: "abdfg",
    6: "abdefg",
    7: "acf",
    8: "abcdefg",
    9: "abcdfg",
}

p1 = 0
p2 = 0


def find_permutation(before):
    for perm in itertools.permutations(list(range(8))):
        mp = {}
        ok = True
        for i in range(8):
            mp[chr(ord("a") + i)] = chr(ord("a") + perm[i])
        for w in before:
            w_perm = ""
            for c in w:
                w_perm += mp[c]
            if w_perm not in digits.values():
                ok = False
        if ok:
            return mp


for line in input:
    before, after = line.split(" | ")
    before = before.split()
    after = after.split()
    mp = find_permutation(before)
    result = ""
    for w in after:
        w_perm = ""
        for c in w:
            w_perm += mp[c]
        w_perm = "".join(sorted(w_perm))
        d = [k for k, v in digits.items() if v == w_perm]
        result += str(d[0])
    p2 += int(result)

print(p1, p2)
