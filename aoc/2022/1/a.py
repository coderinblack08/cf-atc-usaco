with open('./1.txt') as f:
    l = [i.strip() for i in f.readlines()]
    cals = [0]

    for i in l:
      if i == "":
        cals.append(0)
        continue
      cals[-1] += int(i)
    
    print(max(cals))
