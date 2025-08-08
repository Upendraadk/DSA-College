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

def DFS(G, start):
    stack = []
    visited = []
    stack.append(start)
    while(stack):
        poppedVertex = stack.pop()
        visited.append(poppedVertex)
        for chimeki in G[poppedVertex]:
            if chimeki not in stack and chimeki not in visited:
                stack.append(chimeki)
    return visited

start = 'A'
traverse_sequence = DFS(G, start)
print(traverse_sequence)