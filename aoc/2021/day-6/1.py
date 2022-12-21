import fileinput

lines = [i.strip() for i in fileinput.input("aoc/2021/day-6/input.txt")]

fish = [int(i) for i in lines[0].split(",")]

for i in range(1, 257):
    for j in range(len(fish)):
        if fish[j] == 0:
            fish[j] = 6
            fish.append(8)
        else:
            fish[j] -= 1

print(len(fish))
