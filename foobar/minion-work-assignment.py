def solution(data, n): 
    mp = {}
    output = []
    for i in data:
      if i in mp:
        mp[i] += 1
      else:
        mp[i] = 1
    for i in data:
      if mp[i] <= n:
        output.append(i)
    return output

print(solution([1, 2, 2, 3, 3, 3, 4, 5, 5], 1))