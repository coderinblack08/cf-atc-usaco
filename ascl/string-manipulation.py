for _ in range(5):
  s = list(map(lambda x : x.lower() if x.isupper() else x, filter(lambda x : x.isalpha(), input())))
  output = []

  while len(s):
    mp = {}
    new_s = []
    x = []
    for i in s:
      if i in mp:
        new_s.append(i)
      else:
        x.append(i)
        mp[i] = True
    s = new_s
    output += sorted(x)

  last_val = output[0]
  new_output = output[0]
  for i in range(1, len(output)):
    if last_val != output[i]:
      new_output += output[i]
      last_val = output[i]

  print(new_output)