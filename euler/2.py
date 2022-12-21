def fib(n):
  if n <= 1:
    return n
  return fib(n - 1) + fib(n - 2)

i = 0
ans = 0
curr = fib(i)
while curr < 4000000:
  if curr % 2 == 0:
    ans += curr
  i += 1
  curr = fib(i)
print(ans)