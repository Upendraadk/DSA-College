G = {
    'A':['B', 'C'],
    'B':['A', 'D', 'E'],
    'C':['A', 'F'],
    'D':['B', 'G'],
    'E':['B', 'H'],
    'F':['C'],
    'G':['D'],
    'H':['E']
}


def BFS(G, start):
    queue = []
    visited = []
    queue.append(start)
    while(queue):
        outVertex = queue.pop(0)
        visited.append(outVertex)
        for chimeki in G[outVertex]:
            if chimeki not in queue and chimeki not in visited:
                queue.append(chimeki)
    return visited

start = 'A'
traverse_sequence = BFS(G, start)
print(traverse_sequence)