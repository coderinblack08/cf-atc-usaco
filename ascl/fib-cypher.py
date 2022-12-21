from functools import cache
#
# Complete the 'fibCypher' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. CHARACTER key
#  2. STRING msg
#

@cache
def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)

def fibCypher(key, msg):
    # Write your code here
    output = []
    for i, ch in enumerate(msg):
      print(ord(ch), ord(key[i % len(key)]), fib(i + 2))
      offset = ord(key[i % len(key)]) + fib(i + 2)
      offset = (offset - ord("a")) % 26 + ord("a")
      output.append(str(ord(ch) + offset))
    return " ".join(output)

print(fibCypher("h", "ACSL c2"))