# Trie implementation 
import string


class Trie:
  def __init__(self):
    self.root = {}
    self.endOfWord = "#"

  def insert(self, word):
    node = self.root
    for char in word:
      node = node.setdefault(char, {})
    node[self.endOfWord] = self.endOfWord

  def search(self, word):
    node = self.root
    for char in word:
      if char not in node:
        return False
      node = node[char]
    return self.endOfWord in node

  def startsWith(self, prefix):
    node = self.root
    for char in prefix:
      if char not in node:
        return False
      node = node[char]
    return True
  
  # get list of next characters are starting with prefix
  # useful for the stars part
  def getNextChars(self, prefix):
    node = self.root
    for char in prefix:
      if char not in node:
        return []
      node = node[char]
    return [char for char in list(node.keys()) if char in string.ascii_lowercase]

class Tracked:
  def __init__(self, word_idx, word, stars, star_space = False):
    self.word_idx = word_idx
    self.word = word
    self.stars = stars
    self.star_space = star_space

  def __str__(self):
    return "word_idx: {}, word: {}, stars: {}, star_space: {}".format(self.word_idx, self.word, self.stars, self.star_space)

def countNinjaWords(targetWords, sentence):
  # put all target words into a Trie
  trie = Trie()
  for word in targetWords:
    trie.insert(word.lower())

  tracking = []
  points = 0
  word_idx = 0

  for i, char in enumerate(sentence):
    to_remove = set()
    to_add = set()

    if char == " ":
      word_idx += 1
      continue

    # if len(tracking):
    #   print(i, char, len(tracking))

    for j, t in enumerate(tracking):

      if char == "*":
        for star_value in trie.getNextChars(t.word) + [" "]:
          to_add.add(Tracked(word_idx, t.word + ("" if star_value == " " else star_value), t.stars + 1, star_value == " "))
        # remove current t since we've added all permutations of it
        to_remove.add(j)
      else:
        t.word += char

      if trie.search(t.word): 
        if t.word_idx != word_idx or t.star_space:
          points += 1 + t.stars
      
      if not trie.startsWith(t.word):
        to_remove.add(j)

    # delete all indexes in to_remove from tracking
    for j in sorted(to_remove, reverse=True):
      del tracking[j]

    if char == "*":
      for c in string.ascii_lowercase + " ":
        to_add.add(Tracked(word_idx, c if c != " " else "", 1, c == " "))

    if trie.startsWith(char):  
      tracking.append(Tracked(word_idx, char, 0))
    
    for new in to_add:
      # print("add", new)
      tracking.append(new)
  
  return points


print(countNinjaWords(["Sun", "Moon", "Star", "Planet"], "All the stars under the sky twinkle in slo mo on a clear night"))
# == 2

print(countNinjaWords(["Water", "Sea", "Beach", "Lake", "Shells"], "She sells she*lls on the shore for two sand dollar* each"))
# == 6