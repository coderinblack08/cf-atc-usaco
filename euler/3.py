from math import sqrt
n = 600851475143

# def is_prime(x):
#   if x < 2:
#     return False
#   for i in range(2, int(sqrt(x)) + 1):
#     if x % i == 0:
#       return False
#   return True
# for i in range(2, n):
#   if n % i == 0 and is_prime(i):
#     ans = max(ans, i)
# print(ans)

factor = 3
max_factor = sqrt(n)
last_factor = 0

# handle 2 seperately
if n % 2 == 0:
  last_factor = 2
  while n % 2 == 0:
    n = n // 2
  else:
    last_factor = 1

# mathematical insight: ans is necessarily prime because of sieve of eratosthenes (we remove all occurrences of smaller primes)
while n > 1:
  if n % factor == 0:
    last_factor = factor
    while n % factor == 0:
      n //= factor
    max_factor = sqrt(n)
  factor += 2 # 2 is the only even prime, we can increment by 2s
if n == 1:
  print(last_factor)
else:
  print(n)