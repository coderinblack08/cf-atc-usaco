x = [l.strip() for l in open("2.txt")]

total = 0
for l in x:
  x, y = l.split()
  winner = {
    "C": "X",
    "A": "Y",
    "B": "Z",
  }
  loser = {
    "B": "X",
    "C": "Y",
    "A": "Z",
  }
  draw = {
    "A": "X",
    "B": "Y",
    "C": "Z",
  }
  score = {
    "X" : 1,
    "Y": 2,
    "Z": 3,
  }
  # win
  # if winner[y] == x:
  #   total += 6 + score[y]
  # # lose
  # if draw[y] == x:
  #   total += 3 + score[y]
  # if loser[y] == x:
  #   total += 0 + score[y]
  if y == "Z":
    total += 6 + score[winner[x]]
  if y == "Y":
    total += 3 + score[draw[x]]
  if y == "X":
    total += 0 + score[loser[x]]

print(total)
