def value_of_card(card, total):
  if card == 9:
    return 0
  if card == 4:
    return -10
  if card == 0:
    if total + 11 > 99:
      return 1
    else:
      return 11
  return card

def solve():
  line = [int(i) for i in input().split(", ")]
  total = line[0]
  player_cards = line[1:4]
  dealer_cards = []
  for i in range(4, 11):
    if i % 2 == 0:
      player_cards.append(line[i])
    else:
      dealer_cards.append(line[i])
  player_turn = True
  while total < 100:
    # print("Player's turn" if player_turn else "Dealer's turn", total, player_cards, dealer_cards)
    if player_turn:
      if len(player_cards):
        card = player_cards.pop(0)
        total += value_of_card(card, total)
    else:
      if len(dealer_cards):
        card = dealer_cards.pop(0)
        total += value_of_card(card, total)
    player_turn = not player_turn
  if total >= 100:
    print(str(total) + ", " + ("player" if player_turn else "dealer"))

for _ in range(5):
  solve()
