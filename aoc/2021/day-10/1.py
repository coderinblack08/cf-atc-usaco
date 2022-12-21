import fileinput

lines = [i.strip() for i in fileinput.input("aoc/2021/day-10/input.txt")]
ans = 0

point_val = {
    ")": 3,
    "]": 57,
    "}": 1197,
    ">": 25137,
}

for line in lines:
    stack = []
    for c in line:
        closing = "}])>"
        opening = "{[(<"
        if c in closing:
            if len(stack) > 0 and stack[-1] != opening[closing.index(c)]:
                ans += point_val[closing.index(opening.index(stack[-1]))]
            elif len(stack) > 0 and stack[-1] == opening[closing.index(c)]:
                stack.pop()

print(ans)
