x = [l.strip() for l in open("2.txt")]

total = 0
for l in x:
  x, y = l.split()
  winner = {
    "X": "C",
    "Y": "A",
    "Z": "B",
  }
  loser = {
    "X": "B",
    "Y": "C",
    "Z": "A",
  }
  draw = {
    "X": "A",
    "Y": "B",
    "Z": "C",
  }
  score = {
    "X" : 1,
    "Y": 2,
    "Z": 3,
  }
  # win
  if winner[y] == x:
    total += 6 + score[y]
  # lose
  if draw[y] == x:
    total += 3 + score[y]
  if loser[y] == x:
    total += 0 + score[y]

print(total)
