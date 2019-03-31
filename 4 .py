N, M, I, J = [int(e) for e in input().split()]
I -= 1
J -= 1

def steps(x,y):
  return (
    (v[0] + 2, v[1] + 1),
    (v[0] + 2, v[1] - 1),
    (v[0] - 2, v[1] + 1),
    (v[0] - 2, v[1] - 1),
    (v[0] + 1, v[1] + 2),
    (v[0] + 1, v[1] - 2),
    (v[0] - 1, v[1] + 2),
    (v[0] - 1, v[1] - 2),)

travalled = set()
queue = [(0, 0)]
dist = {(0, 0): 0}

while queue:
  v = queue.pop()

  neighbors = steps(v[0],v[1])
  neighbors = (e for e in neighbors if 0 <= e[0] < N and 0 <= e[1] < M)

  for neighbor in [neighbor for neighbor in neighbors if neighbor not in travalled]:
    if neighbor in dist:
      dist[neighbor] = min(dist[neighbor], dist[v] + 1)
    else:
      dist[neighbor] = dist[v] + 1
    travalled.add(neighbor)
    queue.insert(0, neighbor)

if (I, J) in dist:
  print(dist[(I, J)])
else:
  print("NEVAR")

